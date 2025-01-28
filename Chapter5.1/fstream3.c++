#include <fstream>
#include <iostream>
#include <string>

int main() {
    //파일 읽기 준비
    std::ifstream in("C:\\Users\\ehdtk\\Desktop\\other.txt");
    std::string s;
    
    if(in.is_open()) {
        //위치 지정자를 파일 끝으로 옮긴다.
        in.seekg(0,std::ios::end);  //두번째 인자는 파일 내 위치를 의미

        //그리고 그 위치를 읽는다. (파일의 크기)
        int size = in.tellg();  //tellg함수는 위치 지정자의 위치(시작지점으로 부터의)를 반환

        //그 크기의 문자열을 할당한다.
        s.resize(size);

        //위치 지정자를 다시 파일 맨 앞으로 옮긴다.
        in.seekg(0, std::ios::beg);
        // 파일전체내용을읽어서문자열에저장한다.
        in.read(&s[0], size);
        std::cout << s << std::endl;

    } else {
        std::cout << "파일을찾을수없습니다!" << std::endl;
    }
    return 0;
}