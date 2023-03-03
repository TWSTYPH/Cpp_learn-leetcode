#include <iostream>
void test_arr(){
    int array[2][3] = {0, 1, 2, 3, 4, 5};
    std::cout << &array[0][0] << "  " << &array[0][1] << "  " << &array[0][2] << "  " << std::endl;
    std::cout << &array[1][0] << "  " << &array[1][1] << "  " << &array[1][2] << "  " << std::endl;

}

int main(){
    test_arr();
    return 0;

}