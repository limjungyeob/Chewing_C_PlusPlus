#include<iostream>
int main() {
    int a =3;
    int& another_a = a; // another_a�� ���� a�� ������
    //a�� ������ another_a�� �����Ͽ���. �̶� �����ڸ� ���ϴ� �����, ����Ű���� �ϴ� Ÿ�� �ڿ� &�� ���̸� �ȴ�.
    //�߰��� ������ Ÿ���� �����ڸ� ������� int*&�� ����ȴ�.
    another_a = 5;
    std::cout<<"a : " << a <<std::endl;
    std::cout<<"another_a  : " << another_a <<std::endl;
    return 0;
}