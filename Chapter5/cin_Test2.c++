// �ذ���
#include <iostream>
#include <string>

int main() {
    int t;
    while (std::cin >> t) { // ���������ι��ڸ��Է��ϸ�failbit ��������
        std::cout << "�Է�:: " << t << std::endl;
        if (t == 0) break;
    }
}