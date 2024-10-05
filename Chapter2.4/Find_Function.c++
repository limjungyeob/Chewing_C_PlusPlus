#include <iostream>
 // string.h 는strlen 때문에include 했는데, 사실여러분이직접strlen
 // 과같은함수를만들어서써도됩니다.
#include <string.h>

class MyString {
char* string_content; // 문자열데이터를가리키는포인터
    int string_length;
    // 문자열길이
    int memory_capacity; // 현재할당된용량
    public:
        // 문자하나로생성
        MyString(char c);
        // 문자열로부터생성
        MyString(const char* str);
        // 복사생성자
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        int capacity() const;
        void reserve(int size);
        void print() const;
        void println() const;
        MyString& assign(const MyString& str);
        MyString& assign(const char* str);
        char at(int i) const;
        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, char c);
        MyString& erase(int loc, int num);
        int find(int find_from, const MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 그러면다시할당을해줘야만한다.
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    // 그리고굳이str.string_length + 1 ~ string_length 부분은초기화
    // 시킬필요는없다. 왜냐하면거기까지는읽어들이지않기때문이다.
    string_length = str.string_length;
    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면다시할당을해줘야만한다.
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}
int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
    // 만일예약하려는size 가현재capacity 보다작다면
    // 아무것도안해도된다.
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    // 이는i 의위치바로앞에문자를삽입하게된다. 예를들어서
    // abc 라는문자열에insert(1, "d") 를하게된다면adbc 가된다.
    // 범위를벗어나는입력에대해서는삽입을수행하지않는다.
    if (loc < 0 || loc > string_length) return *this;
    if (string_length + str.string_length > memory_capacity) {
        // 이제새롭게동적으로할당을해야한다.
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        // 일단insert 되는부분직전까지의내용을복사한다.
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        // 그리고새롭에insert 되는문자열을넣는다.
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        // 이제다시원문자열의나머지뒷부분을복사한다.
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }
    // 만일초과하지않는경우굳이동적할당을할필요가없게된다.
    // 효율적으로insert 하기위해, 밀리는부분을먼저뒤로밀어버린다.
    for (int i = string_length- 1; i >= loc; i--) {
        // 뒤로밀기. 이때원래의문자열데이터가사라지지않게함
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고insert 되는문자다시집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc 의앞부터시작해서num 문자를지운다.
    if (num < 0 || loc < 0 || loc > string_length) return *this;
    // 지운다는것은단순히뒤의문자들을앞으로끌고온다고
    // 생각하면됩니다.
    for (int i = loc + num; i < string_length; i++) {
        string_content[i- num] = string_content[i];
    }
    string_length-= num;
    return *this;
}
int MyString::find(int find_from, const MyString& str) const {\
    // find_from 에서 부터 시작해서 가장 첫번째 str의 위치를 리턴하게 된다.
    //string_content와 str가 완벽히 일치하는 부분이 생긴다면 그 위치를 리턴한다.
    //str이 문자열에 포함되어 있지만 않다면, -1를 리턴하게 된다.
    int i, j;
    if (str.string_length == 0) return-1;
    for (i = find_from; i <= string_length- str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }
        if (j == str.string_length) return i;
    }
    return-1; // 찾지못했음
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int main() {
    MyString str1("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str1.find(0, "very") << std::endl;
    std::cout << "Location of second <very> in the string : " << str1.find(str1.find(0, "very") + 1, "very") << std::endl;
    //첫번째 위치를 찾은 다음 이전의 검색 한 위치 바로 다음 부터 very를 찾는것.
}
