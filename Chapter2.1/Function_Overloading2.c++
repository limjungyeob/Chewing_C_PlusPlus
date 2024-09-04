/* 함수의오버로딩*/
#include <iostream>
    void print(int x) { std::cout << "int : " << x << std::endl; }
    void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    //print를 호출하는 함수중 char로 받는 인자는 없고 int와 double밖에 없음.
    //C++ 컴파일러는 자신과 최대로 근접한 함수를 찾게 됨.
    //찾는 과정을 함수 오버로딩이라고함.
    /*
    1단계 : 자신과 타입이 정확히 일치하는 함수를 찾는다.

    2단계 : 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
    2.1 char, unsigned char, short는 int로 변환된다.
    2.2 unsigned short는 int의 크기에 따라 int 혹은 unsigned int로 변환된다.
    2.3 float은 double로 변환된다.
    2.4 Enum은 int로 변환된다.
    3단계 : 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀 더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.

    3.1 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를들어 float -> int)
    3.2 Enum도 임의의 숫자 타입으로 변환된다. (예를 들어 Enum -> double)
    3.3 0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환된다.
    3.4 포인터는 void 포인터로 변환된다.

    4단계 유저 정의도니 타입 변환으로 일치하는 것을 찾는다.
    만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에 모호하다 (ambiguous) 라고 판단해서 오류를 발생하게 된다.
    ex) 
    void print(char x) { std::cout << "char : " << x << std::endl; }
    double c = 3.2f;
    print(c);
    1단계에서 명백하게 일치하는 것이 없다.
    2단계에서는 마찬기지로 double의 캐스팅에 관련한 내용이 없기에 일치하는 것이 없고
    3단계에서는 임의의 숫자 타입이 임의의 숫자 타입으로 변환된다고 생각하기 때문에 dobule은 char도 int도 변환되게 할 수 있다.(모호하다) 이때 오류 발생.
    */
    double c = 3.2f;

    print(a);
    print(b);
    print(c);

    return 0;
}