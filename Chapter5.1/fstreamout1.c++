#include <fstream>
#include <iostream>
#include <string>
int main() {
// ���Ͼ����غ�
    std::ofstream out("C:\\Users\\ehdtk\\Desktop\\test.txt", std::ios::app);
    std::string s;
    if (out.is_open()) {
        out << "�����̱�";
    }
    return 0;
}