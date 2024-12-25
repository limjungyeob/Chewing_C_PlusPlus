#include<iostream>
#include<string>

class Base {
    std::string s;

    public:
        Base() : s("���") {
            std::cout << "��� Ŭ����" << std::endl;
        }

        void what() {
            std::cout << s <<std::endl;
        }
};

class Derived : public Base {
    std::string s;
    public:
        Derived() : s("�Ļ�"), Base() {
            std::cout<<"�Ļ� Ŭ����" <<std::endl;
        }
        void what() {
            std::cout<<s<<std::endl;
        }
};

int main() {
    Base p;
    Derived c;

    std::cout<< "=== ������ ���� ===" <<std::endl;
    Base* p_p = &c;
    Derived* p_c = static_cast<Derived*>(p_p);
    p_p->what();
    // �����Ϸ� �󿡼� �Ժη� �ٿ� ĳ���� �ϴ� ���� �����ϰ� �ִ�.
    return 0;
}