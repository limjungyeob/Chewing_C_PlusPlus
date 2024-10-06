//mutable�� �����Ͽ��ٸ�, const �Լ������� �̵� ���� �ٲ� �� �ִ�.
#include <iostream>
class A {
    mutable int data_;
    public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x; // �Ұ���!
    }

void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}
/*
mutable�� �ʿ��� ������ ���� const ��� �Լ� ������ ��� ������ ������ �� ������,
 ��Ȥ ĳ�� ������Ʈ�� �Ҷ� ĳ�� ������ ������ �ٲ���� ��, ���δ�. ���� ������ ������, �Ұ��� �ϰ� ��� ������ �����ؾ��� �� ���δ�.
*/