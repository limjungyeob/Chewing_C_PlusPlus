#include <iostream>
class Marine {
    int hp; // ���� ü��
    int coord_x, coord_y; // ���� ��ġ
    bool is_dead;
    const int default_damage; // �⺻ ���ݷ�
    //�ٸ� ���α׷��Ӱ� default_damage�� �����ϴ� ����� ���� �ִ��� ������ ������ �߻��ϱ� ������ ������ �̿��� ������ �� �ִ�.
    public:
        Marine(); // �⺻ ������
        Marine(int x, int y); // x, y ��ǥ�� ���� ����
        int attack(); // �������� �����Ѵ�.
        void be_attacked(int damage_earn); // �Դ� ������
        void move(int x, int y); // ���ο� ��ġ
        void show_status(); // ���¸� �����ش�.
};
//�� �κ��� �ʱ�ȭ ����Ʈ(initializer list) ��� �θ���. ������ ȣ��� ���ÿ� ��� �������� �ʱ�ȭ�ϰ� ���ش�.
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}
//ex) (������ �������̸�) : var(ar1), var2(arg2) {}
//�ʱ�ȭ ����Ʈ�� ������� �ʴ´ٸ� ������ ���� �ϰ� �� ������ ������ �����Ѵ�.
//���� ���� int a = 10; �� int a; a = 10;�� ���� �̴�.
//���࿡ int ��ſ� Ŭ���� ���ٸ�, ������ ��� ���� �����ڰ� ȣ��Ǵµ�, ������ ��� ����Ʈ �����ڰ� ȣ���� ������
// ������ �����Ѵ�.
// ������ ���ڰ� ���� ���ϴ� �۾��� ���� �ȴ�.
// ���� �ʱ�ȭ ����Ʈ�� ����ϴ� ���� ���� �� ȿ������ �۾��̶�� ������� �� �ִ�.
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
    std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}