#include <iostream>

class Marine {
    int hp;
    // 마린체력
    int coord_x, coord_y; // 마린위치
    int damage;
    // 공격력
    bool is_dead;

    public:
        Marine();   // 기본생성자
        Marine(int x, int y); // x, y 좌표에마린생성
        int attack();   // 데미지를리턴한다.
        void be_attacked(int damage_earn); // 입는데미지
        void move(int x, int y);    // 새로운위치
        void show_status(); // 상태를보여준다.
 };

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp-= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
/* int main 전까지내용은동일*/
int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);
    marines[0]->show_status();
    marines[1]->show_status();
    std::cout << std::endl << "마린1 이마린2 를공격! " << std::endl;
    marines[0]->be_attacked(marines[1]->attack());
    marines[0]->show_status();
    marines[1]->show_status();
    delete marines[0];
    delete marines[1];
}