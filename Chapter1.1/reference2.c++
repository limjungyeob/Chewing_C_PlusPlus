#include<iostream>
int main() {
    int a =3;
    int& another_a = a; // another_a는 이제 a의 참조자
    //a의 참조자 another_a를 정의하였다. 이때 참조자를 정하는 방법은, 가리키고자 하는 타입 뒤에 &를 붙이면 된다.
    //추가로 포인터 타입의 참조자를 만드려면 int*&로 쓰면된다.
    another_a = 5;
    std::cout<<"a : " << a <<std::endl;
    std::cout<<"another_a  : " << another_a <<std::endl;
    return 0;
}