#ifndef UTILS_H
#define UTILS_H
/*
    Include Guards
    헤더 파일이 여러번 포함되는 것을 방지하느 기술.
    헤더 파일이 여러번 포함될 때 같은 선언이 여러 번 되어 컴파일에러가 발생할 수 있다.
    그래서 
    #ifndef UTILS_H "UTILS_H"가 정의되어 있지 않다면 이후의 코드를 실행하라는 지시를 의미
    #define UTILS_H "UTILS_H"를 정의합니다. 이로써 해당 파일의 나머지 부분이 처음 포함될 때만 처리되도록 보장

    ~
    #endif로 묶어서 헤더 파일이 한 번만 포함되도록 보장하여, 중복 선언과 같은 문제들을 예방 할 수 있다.

*/
#include <string>
using std::string;
/*
    코드를 논리적으로 그룹화하고, 이름 충돌을 방지하려고 namespace로 그룹화함.
    namespace MyExcel는 선언된 모든 요소(클래스, 함수, 변수 등)을 MyExcel이라는 네임스페이스안에
    포함.
    이를 통해 다른 라이브러리나 다른 네임스페이스의 요소와 이름이 겹쳐도 각각을 구분할 수 있음.
    예를 들어 MyExcel::Vector와 다른 라이브러리의 Vector 클래스는 충돌 없이 공존할 수 있음.

    결과적으로 코드의 가독성이 향상되고, 라이브러리 간 혹은 프로젝트 내 다른 코드와의 충돌 없이 
    안전하게 이름을 사용할 수 있음.
*/
namespace MyExcel {
    class Vector {
        string* data;
        int capacity;
        int length;

        public:
            //생성자
            Vector(int n=1);

            //맨 뒤에 새로운 원소를 추가한다.
            void push_back(string s);

            //임의의 위치의 원소에 접근한다
            string operator[](int i);

            // x번 째 위치한 원소를 제거한다.
            void remove(int x);

            // 현재 벡터의 크기를 구한다.
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

        //최상단에 새로운 원소를 추가한다.
        void push(string s);

        //최상단의 원소를 제거하고 반환한다.
        string pop();

        //최상단의 원소를 반환한다. (제거 안함)
        string peek();

        //스택이 비어있는지의 유무를 반환한다.
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