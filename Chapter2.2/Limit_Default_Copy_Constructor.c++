 // 디폴트복사생성자의한계
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
    // 0 이아닌값은if 문에서true 로처리되므로
    // 0 인가아닌가를비교할때그냥if(name) 하면
    // if(name != 0) 과동일한의미를가질수있다.
    // 참고로if 문다음에문장이1 개만온다면
    // 중괄호를생략가능하다.
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
    //여기서 pc2는 디폴트 복사생성자를 호출한다.
    //여기서 hp, shield, ...name까지 모두 같은 값을 갖게된다.
    //여기서 pc1, pc2는 name을 같은 주소값에 동적으로 할당 받게된다.
    //즉 pc1의 name과 pc2의 name은 같은 주소값을 가리키게 된다.
    //이땐 문제가 되지 않는데, 소멸할 때 문제가 된다.
    Photon_Cannon pc2 = pc1;
    //pc1의 내용을 모두 소멸한 동시에 pc2의 name은 해제된 pc1의 name을 가리키고 있다.
    // pc2에선 일단 name은 NULL이 아니기 때문에 deletep[] name을 수행하는데, 이미 해제된 메모리에 접근해서
    //다시 해제하려고 하였기 때문에 런타입 오류 발생함.
    // 해답은 복사 생성자에서 name을 그대로 복사하지 말고 따로 다른 메모리에 동적 할당을해서
    // 그 내용만 복사하면 된다.
    //이렇게 메모리를 새로 할당해서 내용을 복사하는 것은 깊은 복사(deep copy)라고 부르며,
    // Limit_Default_Copy_Constructor처럼 단순히 대입만 해주는 것을 얕은 복사(shallow copy) 라고 부른다.
    // 컴파일러가 생성하는 디폴트 복사 생성자의 경우 얕은 복사 밖에 할 수 없으므로 위와 같이 깊은 복사가 
    // 필요한 경우 사용자가 직접 복사 생성자를 만들어야 한다.
    pc1.show_status();
    pc2.show_status();
}