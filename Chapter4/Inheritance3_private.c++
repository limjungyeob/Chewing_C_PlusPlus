#include <iostream>
#include <string>
class Base {
    public:
        std::string parent_string;
        Base() : parent_string("기반") { std::cout << "기반클래스" << std::endl; }
        void what() { std::cout << parent_string << std::endl; }
};

class Derived : private Base {
    std::string child_string;
    public:
        Derived() : child_string("파생"), Base() {
            std::cout << "파생클래스" << std::endl;
        }
        void what() { std::cout << child_string << std::endl; }
};

int main() {
    Base p;
    // Base 에서는parent_string 이public 이므로
    // 외부에서당연히접근가능하다.
    std::cout << p.parent_string << std::endl;
    Derived c;
    // 반면에Derived 에서는parent_string 이
    // (private 상속을받았기때문에) private 이
    // 되어서외부에서접근이불가능하다.
    //std::cout << c.parent_string << std::endl;
    /*
    ? private : (부모님들한테안가르쳐주는)자신만의비밀번호
    ? protected : 집 현관문비밀번호( 가족들은알지만그외의사람들은접근불가)
    protected라는public과private에중간위치에있는접근지시자를
    지원합니다. 이키워드는,상속받는클래스에서는접근가능하고그외의기타정보는접근불가능
    이라고보시면됩니다.
    ? public : 집주소(가족뿐만이아니라다른사람들도알수있다)
    */
    return 0;
}