// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(const Photon_Cannon& pc);
        void show_status();
};
//복사 생성자의 표준적인 정의
//ex) T(const T& a)
//다른 T의 객체 a를 상수 레퍼런스로 받음.
//여기서 a가 const이기 때문에 복사 생성자 내부에서 a의 데이터를 변경할 수 없고, 오직 새롭게 초기화 되는
// 인스턴스 변수들에게 '복사'만 할 수 있게 된다.
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    //C++ 컴파일러는 아래 문장을 Photo_Cannon pc3(pc2); 와 동일하게 해석한다.
    Photon_Cannon pc3 = pc2;
    pc1.show_status();
    pc2.show_status();
}