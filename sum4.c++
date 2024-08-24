 /* 행운의 숫자 맞추기*/
 #include <iostream>
    int main() {
        int lucky_number = 3;
        std::cout << "input secreat number~" << std::endl;
        int user_input; // 사용자 입력

        while (1) {
            std::cout << "input: ";
            std::cin >> user_input;
            if (lucky_number == user_input) {
                std::cout << "correct~~" << std::endl;
            break;

            } else {
                std::cout << "think again~" << std::endl;
            }
        }
        return 0;
    }