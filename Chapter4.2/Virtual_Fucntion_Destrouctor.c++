#include <iostream>

class Parent {
    public:
        Parent() { std::cout << "Parent 생성자호출" << std::endl; }
        ~Parent() { std::cout << "Parent 소멸자호출" << std::endl; }
};

class Child : public Parent {
    public:
        Child() : Parent() { std::cout << "Child 생성자호출" << std::endl; }
        ~Child() { std::cout << "Child 소멸자호출" << std::endl; }
};

int main() {
    std::cout << "--- 평범한Child 만들었을때---" << std::endl;
    { Child c; }
    std::cout << "--- Parent 포인터로Child 가리켰을때---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
        //Parent 소멸자만 호출되었다. 메모리 누수가 생김.
    }
}