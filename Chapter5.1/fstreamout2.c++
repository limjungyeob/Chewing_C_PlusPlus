// ate 와app
#include <fstream>
#include <iostream>
#include <string>
int main() {
// 두파일에는모두abc 라고써있었습니다.
    std::ofstream out("C:\\Users\\ehdtk\\Desktop\\test.txt", std::ios::app);
    std::ofstream out2("C:\\Users\\ehdtk\\Desktop\\other.txt", std::ios::ate);

    out.seekp(3, std::ios::beg);
    out2.seekp(3, std::ios::beg);
    out << "추가";
    out2 << "추가";
    return 0;
}