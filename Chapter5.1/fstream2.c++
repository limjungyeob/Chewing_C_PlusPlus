#include <fstream>
#include <iostream>
#include <string>

int main() {
    //파일 읽기 준비
    std::ifstream in("C:\\Users\\ehdtk\\Desktop\\test.txt");
    std::string s;

    if(in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열:: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다! " << std::endl;
    }

    in.close();
    //새로운 파일을 읽을 때 close 시켜줘야함.
    in.open("C:\\Users\\ehdtk\\Desktop\\other.txt");
    int  x;
    if(in.is_open()) {
        in.read((char*)(&x),4);
        std::cout << "입력 받은 문자열:: " << s << std::endl;
    } else {
        std::cout << "파일을  찾을 수 없습니다. " << std::endl;
    }
     return 0;
}