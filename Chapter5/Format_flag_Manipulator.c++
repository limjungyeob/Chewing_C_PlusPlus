#include <iostream>
#include <string>

int main() {
    int t;
    while(true) {
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        //���� �÷���
        //setf�Լ��� ������ 2���� �ִµ�, �ϳ��� ���ڸ� 1���� �޴� ���̰�
        // �ٸ� �ϳ��� �� ó�� ���ڸ� 2���� ���ϴ� ���̴�.
        //���� 1���� �޴� setf�� �׳� ���ڷ� �� ���� �÷��׸� �����ϴ� ��������,
        //2���� ���ϴ� ���� �� ��° ����(basefield)�� ������ �ʱ�ȭ �ϰ�, ù�� ° ����(hex)�� �����ϴ� ���̴�.
        //���� 2���� ��� �� �������� ���� ó������ �����ϴ� basefield�� ���� �ʱ�ȭ�ϰ�, 16���� �÷��׸� �����Ų��.
        std::cin >> t;
        std::cout << "�Է� :: " << t << std::endl;
        if(std::cin.fail()) {
            std::cout << "����� �Է����ּ���" << std::endl;
            std::cin.clear(); // �÷��׵��� �ʱ�ȭ�ϰ�
            //std::cing.ignore(100,'\n');//���๮�ڰ� ���� ������ �����Ѵ�.
        }
        if( t== 0) break;
    }
}