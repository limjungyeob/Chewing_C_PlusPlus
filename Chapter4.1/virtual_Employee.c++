#include <iostream>
#include <string>
class Employee {
    protected:
        std::string name;
        int age;
        std::string position; // 직책(이름)
        int rank;
        // 순위(값이클수록높은순위)
    public:
        Employee(std::string name, int age, std::string position, int rank)
        : name(name), age(age), position(position), rank(rank) {}

        // 복사생성자
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        // 디폴트생성자
        Employee() {}
        //가상 함수
        virtual void print_info() {
            std::cout << name << " (" << position << " , " << age << ") ==> "
            << calculate_pay() << "만원" << std::endl;
        }
        //가상 함수
        virtual int calculate_pay() { return 200 + rank * 50; }
    };
class Manager : public Employee {
    int year_of_service;
    public:
        Manager(std::string name, int age, std::string position, int rank,
        int year_of_service)
        : year_of_service(year_of_service), Employee(name, age, position, rank) {}
        //Overide
        int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
        //Overide
        void print_info() override {
            std::cout << name << " (" << position << " , " << age << ", "
            << year_of_service << "년차) ==> " << calculate_pay() << "만원"
            << std::endl;
        }
};

class EmployeeList {
    int alloc_employee;
    int current_employee;
    // 할당한총직원수
    // 현재직원수
    Employee** employee_list; // 직원데이터
    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }

        void add_employee(Employee* employee) {
            // 사실current_employee 보다alloc_employee 가더
            // 많아지는경우반드시재할당을해야하지만, 여기서는
            // 최대한단순하게생각해서alloc_employee 는
            // 언제나current_employee 보다크다고생각한다.
            // (즉할당된크기는현재총직원수보다많음)
            employee_list[current_employee] = employee;
            current_employee++;
        }

        int current_employee_num() { return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->print_info();
                total_pay += employee_list[i]->calculate_pay();
                }
            std::cout << "총비용: " << total_pay << "만원" << std::endl;
        }
        ~EmployeeList() {
            for (int i = 0; i < current_employee; i++) {
                delete employee_list[i];
            }
            delete[] employee_list;
        }
};
int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
    emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴",-2));
    emp_list.print_employee_info();
    return 0;
}