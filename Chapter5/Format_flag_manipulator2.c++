// �������� ���
#include <iostream>
#include <string>

int main() {
    int t;
    while(true) {
        std::cin >> std::hex >> t;  //16������ ���� �� �ִ� 2��° ���.
        //std::hex���� �Լ��� �����ڶ�� �θ���.
        std::cout << "�Է� ::" << t << std::endl;
        //std::endl�� �� �� ���� ���ٸ� ����ϴ� �� ����, ���۸� ��� ��������(flush) ���ҵ� ����.
        if(std::cin.fail()) {
            std::cout << "����� �Է����ּ���. " << std::endl;
            std::cin.clear();
            std::cin.ignore(100,'n');
        }
        if(t==0) break;
    }
}