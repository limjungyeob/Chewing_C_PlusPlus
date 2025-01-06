#include <iostream>

//���⼭ Animal�� �߻� Ŭ������ �ش��. �ڹٿ� ���� ����.
class Animal {
    public:
        Animal() {}
        virtual ~Animal() {}
        //���� ���� �Լ� : �ڹ��� �������̽��� ����� ����.
        //���� ���� �Լ��� �����ϸ� �� �Լ��� �ݵ�� �������̵��� �ؾ��Ѵ�. ���� �Լ��� =0;�� �ٿ��� ���� ���� �Լ��� ���� �� �ִ�.
        virtual void speak() = 0;
};

class Dog : public Animal {
    public:
        Dog() : Animal() {}
        void speak() override { std::cout << "�п�" << std::endl; }
};

class Cat : public Animal {
    public:
        Cat() : Animal() {}
        void speak() override { std::cout << "�߿˾߿�" << std::endl; }
};
int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    dog->speak();
    cat->speak();
}