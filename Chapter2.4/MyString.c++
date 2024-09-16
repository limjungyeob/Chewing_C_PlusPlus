#include <iostream>
//q 직접 자신만의 문자열 클래스를 만들어 보기로한다.
//문자열 클래스는 아래와 같은 내용들을 지원해야 한다.
//1. 문자(char) 로부터의 문자열 생성, C 문자열 (char *)로 부터의 생성
//2. 문자열 길이를 구하는 함수
//3. 문자열 뒤에 다른 문자열 붙이기
//4. 문자열 내에 포함되어 있는 문자열 구하기
//5. 문자열 내에 포함되어 있는 문자열 구학;
//6. 문자열이 같은지 비교
//7. 문자열 크기 비교(사전 순)
/*
기존 C언어에서는 문자열을 나타내기 위해 널 종료 문자열(Null-testd::minatinf string) 이라는 개념을
도입해서 문자열 끝에 NULL 문자를 붙여 문자열을 나타내는 방식을 사용했다.
하지만 C 언어 문자열을 사용하는데에는 번거로움이 많았는데,C++에서는 표준 라이브러리로 string 클래스를 지원하고 있다.
// 추가로 C++에서는 정말 왠만하면 char 배열을 사용하는 것보다 string을 사용해서 문자열을 다루는 것을 권장한다.
*/
// string.h 는strlen 때문에include 했는데, 사실여러분이직접strlen
// 과같은함수를만들어서써도됩니다.
#include <string.h>

class MyString {
    char* string_content; // 문자열데이터를가리키는포인터
    int string_length;// 문자열길이
    public:
        // 문자하나로생성
        MyString(char c);
        // 문자열로부터생성
        MyString(const char* str);
        // 복사생성자
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        void print() const;
        void println() const;
};
//문자 생성자
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
}
//문자열 생성자
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

//복사 생성자
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
//소멸자
MyString::~MyString() { delete[] string_content; }
//상수 함수
int MyString::length() const { return string_length; }
//싱수 함수
void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
//상수 함수
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
int main() {
    MyString str1("hello world!");
    MyString str2(str1);
    str1.println();
    str2.println();
}