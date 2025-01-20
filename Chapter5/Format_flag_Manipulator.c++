#include <iostream>
#include <string>

int main() {
    int t;
    while(true) {
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        //형식 플래그
        //setf함수의 버전은 2개가 있는데, 하나는 인자를 1개를 받는 것이고
        // 다른 하나는 위 처럼 인자를 2개를 취하는 것이다.
        //인자 1개를 받는 setf는 그냥 인자로 준 형식 플래그를 적용하는 것이지만,
        //2개를 취하는 것은 두 번째 인자(basefield)의 내용을 초기화 하고, 첫번 째 인자(hex)를 적용하는 것이다.
        //인자 2개의 경우 몇 진법으로 수를 처리할지 보관하는 basefield의 값을 초기화하고, 16진법 플래그를 적용시킨것.
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if(std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear(); // 플래그들을 초기화하고
            //std::cing.ignore(100,'\n');//개행문자가 나올 때까지 무시한다.
        }
        if( t== 0) break;
    }
}