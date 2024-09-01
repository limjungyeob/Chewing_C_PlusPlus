#include <iostream>
typedef struct Animal {
    char name[30];  //�̸�
    int age;     // ����
    int health; // ü��
    int food;    // ��θ�����
    int clean; // ����������
    void play() {
        health += 10;
        food-= 20;
        clean-= 30;
    }
    //play�� �ܺο� �������� �ʰ� ����ü Animal�� �����Ͽ���.
} Animal;

void create_animal(Animal *animal) {
    std::cout << "�������̸�? ";
    std::cin >> animal->name;
    std::cout << "�����ǳ���? ";
    std::cin >> animal->age;
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
 }

void one_day_pass(Animal *animal) {
     // �Ϸ簡������
    animal->health-= 10;
    animal->food-= 30;
    animal->clean-= 20;
}

void show_stat(Animal *animal) {
    std::cout << animal->name <<  "�ǻ���" << std::endl;
    std::cout <<  "ü�� : " << animal->health << std::endl;
    std::cout << "��θ�: " << animal->food << std::endl;
    std::cout << "û�� : " << animal->clean << std::endl;
}

int main() {
    Animal *list[10];
    int animal_num = 0;
    for (;;) {
        std::cout <<"1. �����߰��ϱ�" << std::endl;
        std::cout <<"2. ���" << std::endl;
        std::cout <<"3. ���º���"<< std::endl;
        int input;
        std::cin >> input;
        switch (input) {
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "���������? : ";
                std::cin >> play_with;
                if (play_with < animal_num) {
                    list[play_with] -> play();
                    //play(list[play_with]) -> list[play_with] -> play()  ����ü ��ü �Լ��� �����Ͽ� play�Լ��� ���ڸ� ������ �ʿ䵵 ���� �� ��� �Լ� ���ο��� �����.
                }
                break;
            case 3:
                std::cout <<  "����������? : ";
                std::cin >> play_with;
                if (play_with < animal_num) show_stat(list[play_with]);
                break;
        }
        for (int i = 0; i != animal_num; i++) {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}
 