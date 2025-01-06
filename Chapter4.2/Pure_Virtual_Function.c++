#include <iostream>

//여기서 Animal은 추상 클래스에 해당됨. 자바와 거의 동일.
class Animal {
    public:
        Animal() {}
        virtual ~Animal() {}
        //순수 가상 함수 : 자바의 인터페이스와 비슷한 개념.
        //순수 가상 함수로 선언하면 이 함수는 반드시 오버라이딩을 해야한다. 가상 함수에 =0;을 붙여서 순수 가상 함수를 만들 수 있다.
        virtual void speak() = 0;
};

class Dog : public Animal {
    public:
        Dog() : Animal() {}
        void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
    public:
        Cat() : Animal() {}
        void speak() override { std::cout << "야옹야옹" << std::endl; }
};
int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    dog->speak();
    cat->speak();
}