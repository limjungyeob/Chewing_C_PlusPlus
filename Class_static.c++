// static ��� ������ ���
#include <iostream>
class Marine {
    static int total_marine_num;
    //��� ���� ���� static �������� ���ǿ� ���ÿ� ���� �ڵ����� 0���� �ʱ�ȭ �Ǳ� ������ �ʱ�ȭ ���� �ʾƵ� ������ Ŭ���� static �������� ��� �Ʒ��� ���� ������� �ʱ�ȭ�ؾ��Ѵ�.
    //int Marine::total_marine_num = 0;(Ŭ���� �ۿ���)
    int hp; // ���� ü��
    int coord_x, coord_y; // ���� ��ġ
    bool is_dead;
    const int default_damage; // �⺻ ���ݷ�
public:
    Marine(); // �⺻ ������
    Marine(int x, int y); // x, y ��ǥ�� ���� ����
    Marine(int x, int y, int default_damage);
    int attack(); // �������� �����Ѵ�.
    void be_attacked(int damage_earn); // �Դ� ������
    void move(int x, int y); // ���ο� ��ġ
    void show_status(); // ���¸� �����ش�.
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
    std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}
void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
    //�� �Լ��� ���� ��ü�̱� ������ ������ ���ÿ� �Ҹ��� ȣ���Ͽ� ���������� total_marine_num�� 2
}
int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine marine2(3, 5, 10);
    marine2.show_status();
    create_marine();
    std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}