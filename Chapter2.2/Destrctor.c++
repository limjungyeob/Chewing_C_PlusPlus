// 마린의 이름 만들기
#include <string.h>
#include <iostream>

class Marine {
    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    int damage; // 공격력
    bool is_dead;
    char* name; // 마린 이름
    public:
        Marine(); // 기본 생성자
        Marine(int x, int y, const char* marine_name); // 이름까지 지정
        Marine(int x, int y); // x, y 좌표에 마린 생성
        int attack(); // 데미지를 리턴한다.
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치
        void show_status(); // 상태를 보여준다.
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
    //Array_Marine.c++ 에서 name만 추가됨.
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    //name을 동적으로 생성해서 문자열을 복사하였는데, 이렇게 동적으로 할당된 char배열에 대한 delete는
    //명확히 delete를 지정하지 않는 한 자동으로 delete가 되는 경우는 없다.
    //다시 말해 동작 할당한 name은 메모리 누수(Memory Leak)가 발생한다.
    //이 때 필요한 기능이 소멸자(Destructor)
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {

    Marine* marines[100];
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");
    marines[0]->show_status();
    marines[1]->show_status();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[0]->be_attacked(marines[1]->attack());
    marines[0]->show_status();
    marines[1]->show_status();
    delete marines[0];
    delete marines[1];
}