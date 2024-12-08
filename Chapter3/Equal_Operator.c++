//연산자 함수를 제작할 때, 다음과 같이 제작하면 된다.
//(리턴 타입) operator(연산자) (연산자가 받는 인자.) 
//위 방법 외에는 함수이름으로 연산자를 절대 넣을 수 없다.
 #include <string.h>
 #include <iostream>

class MyString {
    char* string_content; //문자열 데이터를 가리키는 포인터
    int string_length; // 문자열 길이
    int memory_capacity; //현재 할당된 용량
    public:
        // 문자하나로생성
        MyString(char c);

        // 문자열로부터생성
        MyString(const char* str);

        // 복사생성자
        MyString(const MyString& str);

        ~MyString();
        int length() const;
        int capacity() const;
        void reserve(int size);
        void print() const;
        void println() const;
        char at(int i) const;
        int compare(MyString& str);
        //연산자 오버로딩
        bool operator==(MyString& str);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) 
        std::cout << string_content[i];
    std::cout << std::endl;

}
int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
    // 만일예약하려는size 가현재capacity 보다작다면
    // 아무것도안해도된다.
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return 0;
    else
        return string_content[i];
}

int MyString::compare(MyString& str) {
    // (*this)- (str) 을수행해서그1, 0,-1 로그결과를리턴한다
    // 1 은(*this) 가사전식으로더뒤에온다는의미. 0 은두문자열
    // 이같다는의미,-1 은(*this) 사사전식으러더앞에온다는의미이다.
    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return-1;
    }
    // 여기까지했는데끝나지않았다면앞부분까지모두똑같은것이된다.
    // 만일문자열길이가같다면두문자열은아예같은문자열이된다.
    if (string_length == str.string_length) 
        return 0;
    // 참고로abc 와abcd 의크기비교는abcd 가더뒤에오게된다.
    else if (string_length > str.string_length)
        return 1;
    return-1;
}
//연산자 오버로딩
bool MyString::operator==(MyString& str) {
    return !compare(str); // str 과같으면compare 에서0 을리턴한다.
}

int main() {
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");
    if (str1 == str2)
        std::cout << "str1 와 str2 같다." << std::endl;
    else
        std::cout << "st1 와 str2 는 다르다." << std::endl;
}