/*
문자열 처리에서 가장 빈번하게 사용되는 작업으로, 문자열 중간에 다른 문자열을 삽입하는 작업을 예로 들 수있다.

*/
#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
    char* string_content; // 문자열 데이터를 가리키는 포인터
    int string_length; // 문자열 길이
    int memory_capacity; // 현재 할당된 용량
    public:
        // 문자 하나로 생성
        MyString(char c);
        // 문자열로 부터 생성
        MyString(const char* str);
        // 복사 생성자
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
        // 그러면 다시 할당을 해줘야만 한다.
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
    // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 그러면 다시 할당을 해줘야만 한다.
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
    // 만일 예약하려는 size 가 현재 capacity 보다 작다면
    // 아무것도 안해도 된다.
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return 0;
    } else {
        return string_content[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
    // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.
    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length) return *this;
    if (string_length + str.string_length > memory_capacity) {
        // 이전의 assign 함수 처럼 새로 메모리를 하당해야 할 경우와, 굳이 할당할 필요가 없는 경우를 나뉘어서 처리함.
        // 만약 원 문자열 길이 + 새로 삽입되는 문자열 길이가, 현재의 할당된 메모리의 크기보다 크면 새로 할당하고 아니면 할당하지 않는다.
        // 이제 새롭게 동적으로 할당을 해야 한다.
        /*
        
        */
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;
        //메모리를 새로 할당할 때, 이전에 할당된 메모리 주소를 보관하기 위해 만든 prev_string_content
        //이 할당된 메모리를 이용하여 string_content에 삽입된 문자열을 손쉽게 집어 넣을 수 있다.    
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        // 그리고 새롭에 insert 되는 문자열을 넣는다.
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }
    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
    // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
        string_content[i + str.string_length] = string_content[i];
        //ex) abc에서 d를 1의 위치에 삽입한다면 자리가 바뀌는 것들은 bc이므로 abbc -> insert() -> adbc 이렇게 됨.
    }
    // 그리고 insert 되는 문자 다시 집어넣기
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
int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);
    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
    str1.insert(5, str2);
    str1.println();
    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
}