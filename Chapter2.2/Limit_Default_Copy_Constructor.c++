 // ����Ʈ������������Ѱ�
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char *name;
    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char *cannon_name);
        ~Photon_Cannon();
        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() {
    // 0 �̾ƴѰ���if ������true ��ó���ǹǷ�
    // 0 �ΰ��ƴѰ������Ҷ��׳�if(name) �ϸ�
    // if(name != 0) ���������ǹ̸��������ִ�.
    // �����if ��������������1 �����´ٸ�
    // �߰�ȣ�����������ϴ�.
    if (name) {
        delete[] name;
    }
}

void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    //���⼭ pc2�� ����Ʈ ��������ڸ� ȣ���Ѵ�.
    //���⼭ hp, shield, ...name���� ��� ���� ���� ���Եȴ�.
    //���⼭ pc1, pc2�� name�� ���� �ּҰ��� �������� �Ҵ� �ްԵȴ�.
    //�� pc1�� name�� pc2�� name�� ���� �ּҰ��� ����Ű�� �ȴ�.
    //�̶� ������ ���� �ʴµ�, �Ҹ��� �� ������ �ȴ�.
    Photon_Cannon pc2 = pc1;
    //pc1�� ������ ��� �Ҹ��� ���ÿ� pc2�� name�� ������ pc1�� name�� ����Ű�� �ִ�.
    // pc2���� �ϴ� name�� NULL�� �ƴϱ� ������ deletep[] name�� �����ϴµ�, �̹� ������ �޸𸮿� �����ؼ�
    //�ٽ� �����Ϸ��� �Ͽ��� ������ ��Ÿ�� ���� �߻���.
    // �ش��� ���� �����ڿ��� name�� �״�� �������� ���� ���� �ٸ� �޸𸮿� ���� �Ҵ����ؼ�
    // �� ���븸 �����ϸ� �ȴ�.
    //�̷��� �޸𸮸� ���� �Ҵ��ؼ� ������ �����ϴ� ���� ���� ����(deep copy)��� �θ���,
    // Limit_Default_Copy_Constructoró�� �ܼ��� ���Ը� ���ִ� ���� ���� ����(shallow copy) ��� �θ���.
    // �����Ϸ��� �����ϴ� ����Ʈ ���� �������� ��� ���� ���� �ۿ� �� �� �����Ƿ� ���� ���� ���� ���簡 
    // �ʿ��� ��� ����ڰ� ���� ���� �����ڸ� ������ �Ѵ�.
    pc1.show_status();
    pc2.show_status();
}