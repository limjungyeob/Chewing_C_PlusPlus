#include<iostream>
int change_val(int *p){
    *p  = 3;
    return 0;
}
int main() {
    int number = 5;
    std::cout<<number<<std::endl;
    change_val(&number);    
    //change_val함수의 인자 p에 number주솟값을 전달하여 *p를 통해 number를 참조하여 값을 3으로 바꿈.
    std::cout<<number<<std::endl;
}
