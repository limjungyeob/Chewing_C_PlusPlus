#include <iostream>
#include <string>

int main() { 
    std::string s;
    std::cin >> s;

    // 위치 지정자를 한 칸 옮기고, 그 다움 문자를 훔쳐본다. (이 때는 움직이지 않음)
    char peek = std::cin.rdbuf()->snextc();
    //입력 객체 cin의 rdbuf를 호출하게 되면, cin 객체가 입력을 수행하고 있던 streambuf 객체를 가리키는 
    //포인터를 리턴하게 된다.
    //이 때 cin 객체가 istream 객체 이므로, 오직 입력만을 수행하고 있기에, 이 streambuf 객체에는 오직 get area만 있음을 알 수 있다.
    //snextc 함수는 스트림 위치 지정자를 한칸 전진 시킨 후, 그 자리에 해당하는 문자를 엿본다.
    //읽기와 엿본다의 차이점은 보통 streambuf 객체에서 읽게 되면, 스트림 위치 지정자를 한 칸 전진시켜서 
    //다음 읽기 때 다음 문자를 읽을 수 있도록 준비한다.
    //하지만 엿본다는 것은 해당 문자를 읽고도 스트림 위치 지정자를 움직이지 않는 다는 것이다.
    //그래서 hello world의 경우 snextc()가 w를 가리키고 있는 것이다.
    if(std::cin.fail()) std::cout<<"Failed";
    std::cout << "두번째단어맨앞글자: " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시읽으면: " << s << std::endl;
}