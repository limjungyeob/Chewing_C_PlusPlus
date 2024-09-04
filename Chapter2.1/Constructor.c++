#include <iostream>
 class Date {
    int year_;
    int month_; // 1 부터12 까지.
    int day_;   // 1 부터31 까지.
        public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);
        // 해당월의총일수를구한다.
        int GetCurrentMonthTotalDays(int year, int month);
        void ShowDate();
    Date(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
 };
 // 생략
void Date::AddYear(int inc) { year_ += inc; }
    void Date::ShowDate() {
    std::cout << "오늘은" << year_ << " 년" << month_ << " 월" << day_ << " 일입니다" << std::endl;
 }
 int main() {
    Date day(2011, 3, 1); //암시적 방법(implicit)
    day.ShowDate();
    day.AddYear(10);
    day.ShowDate();
    Date day1 = Date(2012,3,1); // 명시적 방법(explicit)
    day1.ShowDate();
 return 0;
 }