#include<iostream>
#include<string>

int main() {
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

    std::cout << s << " �Ǳ��� : " << s.length() << std::endl;
    std::cout << s <<" �ڿ�" << t << "�� ���̸� "<< s + t << std::endl;

    if(s == s2) {
        std::cout <<s <<" ��" << s2 << " �� ����" << std::endl;
    }

    if(s != t) {
        std::cout << s << " ��" << t <<  " �� �ٸ���" << std::endl;
    }

    return 0;
}