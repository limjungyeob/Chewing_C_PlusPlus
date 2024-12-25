#include <iostream>

class Base {
    public:
        Base() {
            std::cout << "��� Ŭ����" << std::endl;
        }
        //�����Լ��� ������ �ÿ� � �Լ��� ����� �� �������� �ʰ� ��Ÿ�� �ÿ� �������� ���� �����Ѽ� ���� ���ε��̶�� �Ҹ���.
        virtual void what() {
            std::cout << "��� Ŭ������ what()" << std::endl;
        }
};

class Derived : public Base {
    public:
        Derived() : Base() {
            std::cout<<"�Ļ� Ŭ����" << std::endl;
        }
        void what() {
            std::cout << "�Ļ� Ŭ������ what()" << std::endl;
        }
};

int main() {
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout<<" == ���� ��ü�� Base =="<< std::endl;

    p_p->what();

    std::cout<<" == ���� ��ü�� Derived == " << std::endl;

    p_c->what();
}