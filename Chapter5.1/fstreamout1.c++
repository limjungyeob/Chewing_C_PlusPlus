#include <fstream>
#include <iostream>
#include <string>
int main() {
// 파일쓰기준비
    std::ofstream out("C:\\Users\\ehdtk\\Desktop\\test.txt", std::ios::app);
    std::string s;
    if (out.is_open()) {
        out << "덧붙이기";
    }
    return 0;
}