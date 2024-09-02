// 디폴트 생성자 정의해보기
#include <iostream>

class Date {
    int year_;
    int month_; // 1 부터 12 까지.
    int day_; // 1 부터 31 까지.
        public:
            void ShowDate();
    Date(bool isDefault) {
        if(isDefault) {
            year_ = 2012;
            month_ = 7;
            day_ = 12;    
        }
    }
    Date() = default;
    //C++ 11 부터 명시적으로 디폴트 생성자를 사용하도록 명시할 수 있습니다.


};
void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다 " << std::endl;
}

int main() {
    Date day = Date(true);
    Date day2;
    day.ShowDate();
    day2.ShowDate();    
    return 0;
}