// ����Ʈ ������ �����غ���
#include <iostream>

class Date {
    int year_;
    int month_; // 1 ���� 12 ����.
    int day_; // 1 ���� 31 ����.
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
    //C++ 11 ���� ��������� ����Ʈ �����ڸ� ����ϵ��� ����� �� �ֽ��ϴ�.


};
void Date::ShowDate() {
    std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_ << " �� �Դϴ� " << std::endl;
}

int main() {
    Date day = Date(true);
    Date day2;
    day.ShowDate();
    day2.ShowDate();    
    return 0;
}