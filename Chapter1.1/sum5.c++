#include<iostream>

int main() {
    int user_input;
    std::cout << "print my information" << std::endl;
    std::cout << "1. name" << std::endl;
    std::cout << "2. age" << std::endl;
    std::cout << "3.sexual " << std::endl;

    std::cin >> user_input;
    switch (user_input)
    {
    case 1:
        std::cout<<"psi !" << std::endl;
        break;
    case 2:
        std::cout<<"99 years old" << std::endl;
        break;
    case 3:
        std::cout<<"male"<<std::endl;
        break;
    case 4:
        std::cout<<"you wouldn't wonder anything !"<<std::endl;
        break;
    default:
        break;
    }
    return 0;
}