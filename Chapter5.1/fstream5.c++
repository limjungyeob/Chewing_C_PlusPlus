//getline���� �ϰϵ��̱�
#include<fstream>
#include<iostream>
#include<string>

int main() {
    //���� �б� �غ�
    std::ifstream in("C:\\Users\\ehdtk\\Desktop\\other.txt");

    if(!in.is_open()) {
        std::cout << "������ ã�� �� �����ϴ�!" <<std::endl;
        return 0;
    }
    std::string s;
    while(in) {
        getline(in,s);
        std::cout<<s<<std::endl;
    }
    return 0;
}