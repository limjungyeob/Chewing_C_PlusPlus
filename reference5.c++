#include <iostream>
 int main() {
    const int &ref = 4;
   //C++ 문법 상 상수 리터럴을 일반적인 레퍼런스가 참조하는 것은 불가능하게 되어 있다.
   //하지만 상수 참조자로 선언한다면 리터럴도 참조 할 수 있다.
    std::cout << ref << std::endl;
 }