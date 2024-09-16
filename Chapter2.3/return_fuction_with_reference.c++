// ���۷����������ϴ��Լ�
#include <iostream>

class A {
    int x;
    public:
        A(int c) : x(c) {}
        //int�� int�� ���۷����� �����ϴ� �ΰ��� �Լ�.
        //access_x�� x�� ���۷����� �����ϰ� �ǰ�
        int& access_x() { return x; }
        //getx�� x�� '��'�� �����ϰ� �ȴ�.
        int get_x() { return x; }
        void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    //���⼭ ���۷��� c�� x�� ���۷��� �� x�� �����̴�.
    //���� c�� x�� �������� ź���ϰԵȴ�.
    //int &c = x;�� �����ϴ�. ���� c�� ���� �ٲٴ� ���� a�� x�� ���� �ٲٴ� �Ͱ� ������ �ǹ��̹Ƿ�
    //show_x�� ���� �ÿ� x�� ���� 5���� 4�� �ٲ�������� �� �� �ִ�.
    int& c = a.access_x();
    c = 4;
    a.show_x();

    //���⼭ int&���ƴ� int���� d�� x�� ������ �ƴ� �Ϲ� ������ �����̴�.
    //�׷��� d = 3; �ص� x�� ���� �ٲ��� ���� ä, �׳� 4���
    int d = a.access_x();
    d = 3;
    a.show_x();

    // �Ʒ��¿���
    // ������ ���۷����� �ƴ� Ÿ���� �����ϴ� ���� '��'�� ���簡 �̷������ ������ �ӽ� ��ü�� �����Ǵµ�,
    // �ӽ� ��ü�� ���䷱���� ���� �� ���⶧���̴�.(�ӽ� ��ü�� ������ ������ �Ǹ� �Ҹ�.)
    // + int& �������� ���� ���۷����̰�, a.get_x()�� �������� ���� ���۷����̴�.
    // a.get_x()�� �������� ���� ���۷����̱� ������ ���۷����� ���� �� ����.
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();
    int f = a.get_x();
    f = 1;
    a.show_x();
}