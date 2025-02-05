#include <iostream>
#include <string>
class Base {
    std::string s;
    public:
        Base() : s("기반") { std::cout << "기반클래스" << std::endl; }
        virtual void incorrect() { std::cout << "기반클래스" << std::endl; }
};

class Derived : public Base {
    std::string s;
    public:
        Derived() : Base(), s("파생") {}
        void incorrect() override { std::cout << "파생클래스" << std::endl; }
};

int main() {
    Base p;
    Derived c;
    Base* p_c = &c;
    Base* p_p = &p;
    std::cout << " == 실제객체는Base == " << std::endl;
    p_p->incorrect();
    std::cout << " == 실제객체는Derived == " << std::endl;
    p_c->incorrect();
    return 0;
}
