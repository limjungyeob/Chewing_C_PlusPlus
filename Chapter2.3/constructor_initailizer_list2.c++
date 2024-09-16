#include <iostream>

class Marine {
    int hp;
    // 마린체력
    int coord_x, coord_y; // 마린위치
    bool is_dead;
    const int default_damage; // 기본공격력
    public:
        Marine();
        // 기본생성자
        Marine(int x, int y); // x, y 좌표에마린생성
        Marine(int x, int y, int default_damage);
        int attack();
        // 데미지를리턴한다.
        void be_attacked(int damage_earn); // 입는데미지
        void move(int x, int y);
        // 새로운위치
        void show_status(); // 상태를보여준다.
};

Marine::Marine()
: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    //const int default_damage = (인자로 받은 default_damage)와 동일하다.
    //default_damage를 생성자를 이용하여 변경할 수 있다.
    default_damage(default_damage),
    is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp-= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10);
    Marine marine2(3, 5, 10);
    marine1.show_status();
    marine2.show_status();
    std::cout << std::endl << "마린1 이마린2 를공격! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}