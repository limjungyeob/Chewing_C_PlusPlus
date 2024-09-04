// new 로배열할당하기
 #include <iostream>
int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    int a=5;
    {
        int a=4;
        std::cout<<"Inside a : " <<a << std::endl;
    }
    std::cout<<"Outside a: " << a<<std::endl;
    delete[] list;
    return 0;
}