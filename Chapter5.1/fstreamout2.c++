// ate ��app
#include <fstream>
#include <iostream>
#include <string>
int main() {
// �����Ͽ��¸��abc �����־����ϴ�.
    std::ofstream out("C:\\Users\\ehdtk\\Desktop\\test.txt", std::ios::app);
    std::ofstream out2("C:\\Users\\ehdtk\\Desktop\\other.txt", std::ios::ate);

    out.seekp(3, std::ios::beg);
    out2.seekp(3, std::ios::beg);
    out << "�߰�";
    out2 << "�߰�";
    return 0;
}