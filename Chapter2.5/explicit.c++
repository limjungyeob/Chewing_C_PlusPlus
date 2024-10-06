#include <iostream>
class MyString {
    char* string_content; // 문자열데이터를가리키는포인터
    int string_length;  // 문자열길이
    int memory_capacity;
    public:
        // capacity 만큼미리할당함.
        MyString(int capacity);

        // 문자열로부터생성
        MyString(const char* str);

        // 복사생성자
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        int getCapacity() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}
MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }
int MyString::getCapacity() const {
    return memory_capacity;
}

int main() { 
    MyString s(3); 
    std::cout<<"Capacity :" << s.getCapacity()<<std::endl;
}