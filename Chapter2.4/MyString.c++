#include <iostream>
//q ���� �ڽŸ��� ���ڿ� Ŭ������ ����� ������Ѵ�.
//���ڿ� Ŭ������ �Ʒ��� ���� ������� �����ؾ� �Ѵ�.
//1. ����(char) �κ����� ���ڿ� ����, C ���ڿ� (char *)�� ������ ����
//2. ���ڿ� ���̸� ���ϴ� �Լ�
//3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
//4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
//5. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ����;
//6. ���ڿ��� ������ ��
//7. ���ڿ� ũ�� ��(���� ��)
/*
���� C������ ���ڿ��� ��Ÿ���� ���� �� ���� ���ڿ�(Null-testd::minatinf string) �̶�� ������
�����ؼ� ���ڿ� ���� NULL ���ڸ� �ٿ� ���ڿ��� ��Ÿ���� ����� ����ߴ�.
������ C ��� ���ڿ��� ����ϴµ����� ���ŷο��� ���Ҵµ�,C++������ ǥ�� ���̺귯���� string Ŭ������ �����ϰ� �ִ�.
// �߰��� C++������ ���� �ظ��ϸ� char �迭�� ����ϴ� �ͺ��� string�� ����ؼ� ���ڿ��� �ٷ�� ���� �����Ѵ�.
*/
// string.h ��strlen ������include �ߴµ�, ��ǿ�����������strlen
// �������Լ��������ᵵ�˴ϴ�.
#include <string.h>

class MyString {
    char* string_content; // ���ڿ������͸�����Ű��������
    int string_length;// ���ڿ�����
    public:
        // �����ϳ��λ���
        MyString(char c);
        // ���ڿ��κ��ͻ���
        MyString(const char* str);
        // ���������
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        void print() const;
        void println() const;
};
//���� ������
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
}
//���ڿ� ������
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

//���� ������
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
//�Ҹ���
MyString::~MyString() { delete[] string_content; }
//��� �Լ�
int MyString::length() const { return string_length; }
//�̼� �Լ�
void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
//��� �Լ�
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
int main() {
    MyString str1("hello world!");
    MyString str2(str1);
    str1.println();
    str2.println();
}