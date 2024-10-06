#include <iostream>
class MyString { 
    char* string_content; // 문자열데이터를가리키는포인터
    int string_length;  // 문자열길이

    int memory_capacity;
    public:
        // capacity 만큼미리할당함. (explicit 키워드에주목)
        explicit MyString(int capacity);

        // 문자열로부터생성
        MyString(const char* str);

        // 복사생성자
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        int capacity() const;
};
// .. (생략) ..
void DoSomethingWithString(MyString s) {
// Do something...
}
int main() {
    //"abc"는 MyString 타입이 아니지만, c++ 컴파일러는 꽤나 똑똑해서  MyString(const char* str)를 통해 암시적 변환함.
    DoSomethingWithString("abc");
    //DoSomethingWithString(3); // ????
    //위의 경우는 암시적 변환을 못한다. 왜나하면 MyString(int capacity)가 explicit로 선언되어 있기 때문이다.
    //explicit로 선언되면 암시적 변환을 수행하지 못하게 막을 수 있다.
    
}