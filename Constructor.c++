#include <iostream>
 class Date {
    int year_;
    int month_; // 1 ����12 ����.
    int day_;   // 1 ����31 ����.
        public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);
        // �ش�������ϼ������Ѵ�.
        int GetCurrentMonthTotalDays(int year, int month);
        void ShowDate();
    Date(int year, int month, int day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
 };
 // ����
void Date::AddYear(int inc) { year_ += inc; }
    void Date::ShowDate() {
    std::cout << "������" << year_ << " ��" << month_ << " ��" << day_ << " ���Դϴ�" << std::endl;
 }
 int main() {
    Date day(2011, 3, 1); //�Ͻ��� ���(implicit)
    day.ShowDate();
    day.AddYear(10);
    day.ShowDate();
    Date day1 = Date(2012,3,1); // ����� ���(explicit)
    day1.ShowDate();
 return 0;
 }