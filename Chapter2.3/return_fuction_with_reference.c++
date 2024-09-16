// 레퍼런스를리턴하는함수
#include <iostream>

class A {
    int x;
    public:
        A(int c) : x(c) {}
        //int와 int의 레퍼런스를 리턴하는 두개의 함수.
        //access_x는 x의 레퍼런스를 리턴하게 되고
        int& access_x() { return x; }
        //getx는 x의 '값'을 리턴하게 된다.
        int get_x() { return x; }
        void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    //여기서 레퍼런스 c는 x의 레퍼런스 즉 x의 별명이다.
    //따라서 c는 x의 별명으로 탄생하게된다.
    //int &c = x;와 동일하다. 따라서 c의 값을 바꾸는 것은 a의 x의 값을 바꾸는 것과 동일한 의미이므로
    //show_x를 실행 시에 x의 값이 5에서 4로 바뀌었음으로 알 수 있다.
    int& c = a.access_x();
    c = 4;
    a.show_x();

    //여기서 int&가아닌 int여서 d는 x의 별명이 아닌 일반 정수형 변수이다.
    //그래서 d = 3; 해도 x의 값은 바뀌지 않은 채, 그냥 4출력
    int d = a.access_x();
    d = 3;
    a.show_x();

    // 아래는오류
    // 이유는 레퍼런스가 아닌 타입을 리턴하는 경우는 '값'의 복사가 이루어지기 때문에 임시 객체가 생성되는데,
    // 임시 객체의 리페런스를 가질 수 없기때문이다.(임시 객체는 문장이 끝나게 되면 소멸.)
    // + int& 좌측값에 대한 레퍼런스이고, a.get_x()는 우측값에 대한 레퍼런스이다.
    // a.get_x()는 우측값에 대한 레퍼런스이기 때문에 레퍼런스를 만들 수 없다.
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();
    int f = a.get_x();
    f = 1;
    a.show_x();
}