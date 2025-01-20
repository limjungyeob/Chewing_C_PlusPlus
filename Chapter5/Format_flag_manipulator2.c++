// 조작자의 사용
#include <iostream>
#include <string>

int main() {
    int t;
    while(true) {
        std::cin >> std::hex >> t;  //16진수로 받을 수 있는 2번째 방법.
        //std::hex같은 함수를 조작자라고 부른다.
        std::cout << "입력 ::" << t << std::endl;
        //std::endl은 한 줄 개행 문다를 출력하는 것 말고도, 버퍼를 모두 내보내는(flush) 역할도 수행.
        if(std::cin.fail()) {
            std::cout << "제대로 입력해주세요. " << std::endl;
            std::cin.clear();
            std::cin.ignore(100,'n');
        }
        if(t==0) break;
    }
}