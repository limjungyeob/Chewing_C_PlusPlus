/*
assign 함수는 '지정하다'라는 뜻을 가진 함수로, 우리가 흔히 생각하는 '='과 동일한 역할을 하게된다.
ex) str.assgin("abs"); -> 문자열 str에는 원래 있었던 문자열이 지워지고 abc가 들어가게 된다.

*/

#include <iostream>
// string.h 는strlen 때문에include 했는데, 사실여러분이직접strlen
// 과같은함수를만들어서써도됩니다.
#include <string.h>

class MyString {
    char* string_content; // 문자열데이터를가리키는포인터
    int string_length;// 문자열길이
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
        char at(int i) const;
        MyString& assign(const MyString& str);
        MyString& assign(const char* str);
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
    // 그리고 굳이str.string_length + 1 ~ string_length 부분은초기화
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
        return NULL;
    } else {
        return string_content[i];
    }

}
int main() {
    MyString str1("very very very long string");
    str1.reserve(30);
    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
    std::cout << "str1.at(str1.lenth()) : " << str1.at(str1.length() -1) << std::endl;
    //마지막 문자열 출력
}
