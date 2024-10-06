#include <iostream>
class MyString { 
    char* string_content; // ���ڿ������͸�����Ű��������
    int string_length;  // ���ڿ�����

    int memory_capacity;
    public:
        // capacity ��ŭ�̸��Ҵ���. (explicit Ű���忡�ָ�)
        explicit MyString(int capacity);

        // ���ڿ��κ��ͻ���
        MyString(const char* str);

        // ���������
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        int capacity() const;
};
// .. (����) ..
void DoSomethingWithString(MyString s) {
// Do something...
}
int main() {
    //"abc"�� MyString Ÿ���� �ƴ�����, c++ �����Ϸ��� �ϳ� �ȶ��ؼ�  MyString(const char* str)�� ���� �Ͻ��� ��ȯ��.
    DoSomethingWithString("abc");
    //DoSomethingWithString(3); // ????
    //���� ���� �Ͻ��� ��ȯ�� ���Ѵ�. �ֳ��ϸ� MyString(int capacity)�� explicit�� ����Ǿ� �ֱ� �����̴�.
    //explicit�� ����Ǹ� �Ͻ��� ��ȯ�� �������� ���ϰ� ���� �� �ִ�.
    
}