#include<iostream>
int change_val(int *p){
    *p  = 3;
    return 0;
}
int main() {
    int number = 5;
    std::cout<<number<<std::endl;
    change_val(&number);    
    //change_val�Լ��� ���� p�� number�ּڰ��� �����Ͽ� *p�� ���� number�� �����Ͽ� ���� 3���� �ٲ�.
    std::cout<<number<<std::endl;
}
