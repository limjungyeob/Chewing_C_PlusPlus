// 복사 생성자의 중요성
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char *name;
    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char *cannon_name);
        Photon_Cannon(const Photon_Cannon &pc);
        ~Photon_Cannon();
        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) {
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    //C++에서 문자열을 다룰 때 C언어 처럼 널 종료 char 배열로 다루는 것은 매우매우 비추한다고 한다.
    //C++ 표준 라이브러리에서 std::string이라는 훌룡한 문자열 클래스를 제공하니까
    //뒤의 강좌들도 꼭 읽어서 사용법을 숙지.
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() {
    if (name) delete[] name;
}

void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;
    pc1.show_status();
    pc2.show_status();
}