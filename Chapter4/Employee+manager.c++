#include <iostream>
#include <string>
class Employee {
    std::string name;
    int age;
    std::string position; // ��å(�̸�)
    int rank;   // ����(����Ŭ���ϳ�������)
    public:
        Employee(std::string name, int age, std::string position, int rank)
        : name(name), age(age), position(position), rank(rank) {}

        // ���������
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }
        // ����Ʈ������
        Employee() {}
        void print_info() {
            std::cout << name << " (" << position << " , " << age << ") ==> "
            << calculate_pay() << "����" << std::endl;
        }

        int calculate_pay() { return 200 + rank * 50; }
};
class Manager {
    std::string name;
    int age;
    std::string position; // ��å(�̸�)
    int rank;   // ����(����Ŭ���ϳ�������)
    int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int
        year_of_service)
        : year_of_service(year_of_service),
        name(name),
        age(age),
        position(position),
        rank(rank) {}

        // ���������
        Manager(const Manager& manager) {
            name = manager.name;
            age = manager.age;
            position = manager.position;
            rank = manager.rank;
            year_of_service = manager.year_of_service;
        }
        // ����Ʈ������
        Manager() {}

        int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
        void print_info() {
            std::cout << name << " (" << position << " , " << age << ", " <<
            year_of_service
            << "����) ==> " << calculate_pay() << "����" << std::endl;
        }
};
class EmployeeList {
    int alloc_employee; // �Ҵ�����������
    int current_employee; // ����������
    int current_manager; // ����Ŵ�����
    Employee** employee_list; // ����������
    Manager** manager_list;
    public:
        // �Ŵ���������
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            manager_list = new Manager*[alloc_employee];
            current_employee = 0;
            current_manager = 0;
        }

        void add_employee(Employee* employee) {
            // ���current_employee ����alloc_employee ����
            // �������°��ݵ�����Ҵ����ؾ�������, ���⼭��
            // �ִ��Ѵܼ��ϰԻ����ؼ�alloc_employee ��
            // ������current_employee ����ũ�ٰ������Ѵ�.
            // (���Ҵ��ũ������������������ٸ���)
            employee_list[current_employee] = employee;
            current_employee++;
        }

        void add_manager(Manager* manager) {
            manager_list[current_manager] = manager;
            current_manager++;
        }

        int current_employee_num() { return current_employee + current_manager; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->print_info();
                total_pay += employee_list[i]->calculate_pay();
            }
            for (int i = 0; i < current_manager; i++) {
                manager_list[i]->print_info();
                total_pay += manager_list[i]->calculate_pay();
            }
            std::cout << "�Ѻ��: " << total_pay << "����" << std::endl;
        }
        
        ~EmployeeList() {
            for (int i = 0; i < current_employee; i++) {
                delete employee_list[i];
            }
            for (int i = 0; i < current_manager; i++) {
                delete manager_list[i];
            }

            delete[] employee_list;
            delete[] manager_list;
        }
};
int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
    emp_list.add_employee(new Employee("����", 34, "����", 1));
    emp_list.add_manager(new Manager("���缮", 41, "����", 7, 12));
    emp_list.add_manager(new Manager("������", 43, "����", 4, 15));
    emp_list.add_manager(new Manager("�ڸ���", 43, "����", 5, 13));
    emp_list.add_employee(new Employee("������", 36, "�븮", 2));
    emp_list.add_employee(new Employee("��", 36, "����",-2));
    emp_list.print_employee_info();
    return 0;
}