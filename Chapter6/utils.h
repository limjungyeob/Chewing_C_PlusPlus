#ifndef UTILS_H
#define UTILS_H
/*
    Include Guards
    ��� ������ ������ ���ԵǴ� ���� �����ϴ� ���.
    ��� ������ ������ ���Ե� �� ���� ������ ���� �� �Ǿ� �����Ͽ����� �߻��� �� �ִ�.
    �׷��� 
    #ifndef UTILS_H "UTILS_H"�� ���ǵǾ� ���� �ʴٸ� ������ �ڵ带 �����϶�� ���ø� �ǹ�
    #define UTILS_H "UTILS_H"�� �����մϴ�. �̷ν� �ش� ������ ������ �κ��� ó�� ���Ե� ���� ó���ǵ��� ����

    ~
    #endif�� ��� ��� ������ �� ���� ���Եǵ��� �����Ͽ�, �ߺ� ����� ���� �������� ���� �� �� �ִ�.

*/
#include <string>
using std::string;
/*
    �ڵ带 �������� �׷�ȭ�ϰ�, �̸� �浹�� �����Ϸ��� namespace�� �׷�ȭ��.
    namespace MyExcel�� ����� ��� ���(Ŭ����, �Լ�, ���� ��)�� MyExcel�̶�� ���ӽ����̽��ȿ�
    ����.
    �̸� ���� �ٸ� ���̺귯���� �ٸ� ���ӽ����̽��� ��ҿ� �̸��� ���ĵ� ������ ������ �� ����.
    ���� ��� MyExcel::Vector�� �ٸ� ���̺귯���� Vector Ŭ������ �浹 ���� ������ �� ����.

    ��������� �ڵ��� �������� ���ǰ�, ���̺귯�� �� Ȥ�� ������Ʈ �� �ٸ� �ڵ���� �浹 ���� 
    �����ϰ� �̸��� ����� �� ����.
*/
namespace MyExcel {
    class Vector {
        string* data;
        int capacity;
        int length;

        public:
            //������
            Vector(int n=1);

            //�� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
            void push_back(string s);

            //������ ��ġ�� ���ҿ� �����Ѵ�
            string operator[](int i);

            // x�� ° ��ġ�� ���Ҹ� �����Ѵ�.
            void remove(int x);

            // ���� ������ ũ�⸦ ���Ѵ�.
            int size();

            ~Vector();

    };
    class Stack {
        struct Node {
            Node* prev;
            string s;

            Node(Node* prev, string s) : prev(prev), s(s) {}
        };
        Node* current;
        Node start;

        public:
        Stack();

        //�ֻ�ܿ� ���ο� ���Ҹ� �߰��Ѵ�.
        void push(string s);

        //�ֻ���� ���Ҹ� �����ϰ� ��ȯ�Ѵ�.
        string pop();

        //�ֻ���� ���Ҹ� ��ȯ�Ѵ�. (���� ����)
        string peek();

        //������ ����ִ����� ������ ��ȯ�Ѵ�.
        bool is_empty();
        ~Stack();
    };

    class NumStack {
        struct Node {
            Node* prev;
            double s;

            Node(Node* prev, double s) : prev(prev), s(s) {}
        };

        Node* current;
        Node start;

        public :
            NumStack();
            void push(double s);
            double pop();
            double peek();
            bool is_empty();

            ~NumStack();
    };
}
#endif