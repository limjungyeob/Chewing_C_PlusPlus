#include<iostream>
#include<string>

class Base {
    std::string s;

    public:
        Base() : s("기반") {
            std::cout << "기반 클래스" << std::endl;
        }

        void what() {
            std::cout << s <<std::endl;
        }
};

class Derived : public Base {
    std::string s;
    public:
        Derived() : s("파생"), Base() {
            std::cout<<"파생 클래스" <<std::endl;
        }
        void what() {
            std::cout<<s<<std::endl;
        }
};

int main() {
    Base p;
    Derived c;

    std::cout<< "=== 포인터 버전 ===" <<std::endl;
    Base* p_p = &c;
    Derived* p_c = static_cast<Derived*>(p_p);
    p_p->what();
    // 컴파일러 상에서 함부로 다운 캐스팅 하는 것을 금지하고 있다.
    return 0;
}