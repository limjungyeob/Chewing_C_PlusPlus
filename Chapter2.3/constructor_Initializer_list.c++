#include <iostream>
class Marine {
    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    bool is_dead;
    const int default_damage; // 기본 공격력
    //다른 프로그래머가 default_damage를 변경하는 명령을 집어 넣더라도 컴파일 오류가 발생하기 때문에 오류를 미연에 방지할 수 있다.
    public:
        Marine(); // 기본 생성자
        Marine(int x, int y); // x, y 좌표에 마린 생성
        int attack(); // 데미지를 리턴한다.
        void be_attacked(int damage_earn); // 입는 데미지
        void move(int x, int y); // 새로운 위치
        void show_status(); // 상태를 보여준다.
};
//이 부분이 초기화 리스트(initializer list) 라고 부른다. 생성자 호출과 동시에 멤버 변수들을 초기화하게 해준다.
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}
//ex) (생성자 생성자이름) : var(ar1), var2(arg2) {}
//초기화 리스트를 사용하지 않는다면 생성을 먼저 하고 그 다음에 대입을 수행한다.
//쉽게 말해 int a = 10; 과 int a; a = 10;의 차이 이다.
//만약에 int 대신에 클래스 였다면, 전자의 경우 복사 생성자가 호출되는데, 후자의 경우 디폴트 생성자가 호출한 다음에
// 대입이 수행한다.
// 딱봐도 후자가 조금 더하는 작업이 많게 된다.
// 따라서 초기화 리스트를 사용하는 것이 조금 더 효율적인 작업이라는 사실을알 수 있다.
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
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    marine1.show_status();
    marine2.show_status();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}