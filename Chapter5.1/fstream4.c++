//getline���� �ϰϵ��̱�
#include<fstream>
#include<iostream>
#include<string>

int main() {
    //���� �б� �غ�
    std::ifstream in("C:\\Users\\ehdtk\\Desktop\\other.txt");
    char buf[100];

    if(!in.is_open()) {
        std::cout << "������ ã�� �� �����ϴ�!" <<std::endl;
        return 0;
    }

    while(in) {
        in.getline(buf,100);
        std::cout<<buf<<std::endl;
    }
    return 0;
}