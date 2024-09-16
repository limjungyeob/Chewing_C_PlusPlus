// static 멤버 변수의 사용
//Q 
//1. 어떠한 배열에 Marine을 보관해 놓고, 생성된 마린의 개수를 모두 센다.
//2. 어떤 변수를 만들어서 Marine의 생성시에 1을 추가하고, 소멸시에 1을 뺀다.
//1의 경우 따로 크기가 자유자래로 변할 수 있는 배열을 따로 만들어야 하는 문제점이 있다.
//2의 경우 만일 어떠한 함수 내에서 이런 변수를 정의하였다면 다른 함수에서도 그 값을 이용하기 위해 
//인자로 계속 전달해야 하는 귀찮음이 있다.

//+ 1의 경우 vertor라는 자료형을 이용하여 쉽게 할수 있겠지만 나중에 또 언급한다고 함.
// + 전역 변수로 만들 수 있지만, 전역 변수의 경우 프로젝트의 크기가 커질 수 록 프로그래머의 실수로 인해
// 서로 겹쳐서 오류가 날 가능성이 다분하기에 반드시 필요한 경우가 아니면 사용을 하지 않는다.
// C++에서는 위와 같은 문제를 간단하게 해결하기 위해 전역 변수 같지만 클래스 하나에만 종속되는 변수인
// static 멤버 변수를 사용하면 된다.

//어떤 클래스의 static 멤버 변수의 경우 멤버 변수들 처럼, 객체가 소멸될 때 소멸되는 것이 아닌 
//프로그램이 종료될 때 소멸되는 것이다.
#include <iostream>

class Marine {
    //클래스 static 변수
    static int total_marine_num;
    //모든 전역 변수 static 변수들은 정의와 동시에 값이 자동으로 0으로 초기화 되기 때문에 초기화 하지 않아도
    //되지만 클래스 static 변수들의 경우 아래와 같은 방법으로 초기화해야한다.
    //int Marine::total_marine_num = 0;(클래스 밖에서)
    //static int total_marine_num = 0;은 불가능하다. const static int total_marine_num = 0;은 가능.
    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    bool is_dead;
    const int default_damage; // 기본 공격력
    public:
        Marine(); // 기본 생성자
        Marine(int x, int y); // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);
        int attack(); // 데미지를 리턴한다.
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치
        void show_status(); // 상태를 보여준다.
        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
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

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "<< std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}
void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
    //이 함수는 지역 객체이기 때문에 생성과 동시에 소멸자 호출하여 최종적으로 total_marine_num은 2
}
int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine marine2(3, 5, 10);
    marine2.show_status();
    create_marine();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}