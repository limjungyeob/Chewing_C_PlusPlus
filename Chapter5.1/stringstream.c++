#include <iostream>
#include <sstream>

int main() {
    //���ڿ��� �ϳ��� ��Ʈ���̶� �����ϰ� ���ִ� ����ȭ ��ġ
    std::istringstream ss("123");
    int x;
    ss >> x;
    std::cout << "�Է¹���������:: " << x << std::endl;
    return 0;
}