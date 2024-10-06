//mutable로 선언하였다면, const 함수에서도 이들 값을 바꿀 수 있다.
#include <iostream>
class A {
    mutable int data_;
    public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x; // 불가능!
    }

void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}
/*
mutable이 필요한 이유는 보통 const 멤버 함수 내에서 멤버 변수를 수정할 수 없지만,
 간혹 캐쉬 업데이트를 할때 캐쉬 내부의 정보를 바꿔야할 때, 쓰인다. 자주 쓰이진 않지만, 불가피 하게 멤버 변수를 수정해야할 때 쓰인다.
*/