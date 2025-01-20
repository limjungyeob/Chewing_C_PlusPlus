// 해결방안
#include <iostream>
#include <string>

int main() {
    int t;
    while (std::cin >> t) { // 고의적으로문자를입력하면failbit 가켜진다
        std::cout << "입력:: " << t << std::endl;
        if (t == 0) break;
    }
}