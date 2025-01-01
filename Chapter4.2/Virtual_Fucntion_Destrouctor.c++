#include <iostream>

class Parent {
    public:
        Parent() { std::cout << "Parent ������ȣ��" << std::endl; }
        ~Parent() { std::cout << "Parent �Ҹ���ȣ��" << std::endl; }
};

class Child : public Parent {
    public:
        Child() : Parent() { std::cout << "Child ������ȣ��" << std::endl; }
        ~Child() { std::cout << "Child �Ҹ���ȣ��" << std::endl; }
};

int main() {
    std::cout << "--- �����Child ���������---" << std::endl;
    { Child c; }
    std::cout << "--- Parent �����ͷ�Child ����������---" << std::endl;
    {
        Parent *p = new Child();
        delete p;
        //Parent �Ҹ��ڸ� ȣ��Ǿ���. �޸� ������ ����.
    }
}