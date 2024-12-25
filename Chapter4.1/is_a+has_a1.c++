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
    std::cout << " === ���Ŭ��������===" << std::endl;
    Base p;
    p.what();
    std::cout << " === �Ļ�Ŭ��������===" << std::endl;
    Derived c;
    c.what();
    return 0;
}