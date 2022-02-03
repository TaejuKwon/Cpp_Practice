#include <iostream>

int main() {
    int a = 3;
    int& another_a = a;         // int 뒤에 & : 참조자(reference)
                                // pointer 타입의 참조자 : int*&
    another_a = 5;
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;

    return 0;

}