#include <iostream>
#include <string>
class Base {
    public:
        std::string parent_string;
        Base() : parent_string("���") { std::cout << "���Ŭ����" << std::endl; }
        void what() { std::cout << parent_string << std::endl; }
};

class Derived : private Base {
    std::string child_string;
    public:
        Derived() : child_string("�Ļ�"), Base() {
            std::cout << "�Ļ�Ŭ����" << std::endl;
        }
        void what() { std::cout << child_string << std::endl; }
};

int main() {
    Base p;
    // Base ������parent_string ��public �̹Ƿ�
    // �ܺο����翬�����ٰ����ϴ�.
    std::cout << p.parent_string << std::endl;
    Derived c;
    // �ݸ鿡Derived ������parent_string ��
    // (private ������޾ұ⶧����) private ��
    // �Ǿ�ܺο��������̺Ұ����ϴ�.
    //std::cout << c.parent_string << std::endl;
    /*
    ? private : (�θ�Ե����׾Ȱ������ִ�)�ڽŸ��Ǻ�й�ȣ
    ? protected : �� ��������й�ȣ( ���������������׿��ǻ���������ٺҰ�)
    protected���public��private���߰���ġ���ִ����������ڸ�
    �����մϴ�. ��Ű�����,��ӹ޴�Ŭ�������������ٰ����ϰ�׿��Ǳ�Ÿ���������ٺҰ���
    �̶���ø�˴ϴ�.
    ? public : ���ּ�(�����Ӹ��̾ƴ϶�ٸ�����鵵�˼��ִ�)
    */
    return 0;
}