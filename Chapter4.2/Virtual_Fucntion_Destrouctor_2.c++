#include <iostream>

class Parent {
    public:
        Parent() { std::cout << "Parent 생성자호출" << std::endl; }
        virtual ~Parent() { std::cout << "Parent 소멸자호출" << std::endl; }
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
        //Parent의 소멸자를 Virtual로 선언하게되면, 이는 Child 소멸자를 호출하면서, Child 소멸자가 ’알아서’ Parent 의 소멸자도 호출
    }
}