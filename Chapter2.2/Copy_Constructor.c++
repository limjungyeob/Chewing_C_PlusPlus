// ����ĳ��
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
//���� �������� ǥ������ ����
//ex) T(const T& a)
//�ٸ� T�� ��ü a�� ��� ���۷����� ����.
//���⼭ a�� const�̱� ������ ���� ������ ���ο��� a�� �����͸� ������ �� ����, ���� ���Ӱ� �ʱ�ȭ �Ǵ�
// �ν��Ͻ� �����鿡�� '����'�� �� �� �ְ� �ȴ�.
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "���� ������ ȣ�� !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "������ ȣ�� !" << std::endl;
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
    //C++ �����Ϸ��� �Ʒ� ������ Photo_Cannon pc3(pc2); �� �����ϰ� �ؼ��Ѵ�.
    Photon_Cannon pc3 = pc2;
    pc1.show_status();
    pc2.show_status();
}