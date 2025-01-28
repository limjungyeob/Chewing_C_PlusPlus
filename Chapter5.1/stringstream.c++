#include <iostream>
#include <sstream>

int main() {
    //문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치
    std::istringstream ss("123");
    int x;
    ss >> x;
    std::cout << "입력받은데이터:: " << x << std::endl;
    return 0;
}