// 상수멤버함수
//c++에서는 변수둘의 값을 바꾸지 않고 읽기만 하는 마치 멤버 함수를 '상수 함수'로써 선언할 수 있다.
#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;
    int hp; // 마린체력
    int coord_x, coord_y; // 마린위치
    bool is_dead;
    const int default_damage; // 기본공격력
    public:
        Marine();
        // 기본생성자
        Marine(int x, int y); // x, y 좌표에마린생성
        Marine(int x, int y, int default_damage);
        int attack() const; // 데미지를리턴한다.
        Marine& be_attacked(int damage_earn); // 입는데미지
        void move(int x, int y);    // 새로운위치
        void show_status();     // 상태를보여준다.
        static void show_total_marine();
        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
    std::cout << "전체마린수: " << total_marine_num << std::endl;
}

Marine::Marine()
: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(5),
    is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

//상수 함수의 경우 const 키워드를 꼭 넣어주어야 한다.
// 이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 프로그래머에게 명시 시킬 수 있다.
//당연하게도, 상수 함수 내에서는 객체들의 '읽기'만이 수행되며, 상수 함수 내에서 호출 할 수 있는 함수로는
//상수 함수 밖에 없다.
int Marine::attack() const { return default_damage; }
    Marine& Marine::be_attacked(int damage_earn) {
    hp-= damage_earn;
    if (hp <= 0) is_dead = true;
    return *this;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재총마린수: " << total_marine_num << std::endl;
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine marine2(3, 5, 10);
    marine2.show_status();
    std::cout << std::endl << "마린1 이 마린2 를두번공격! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}