#include <iostream>

int main() {
    int* p = new int;   //malloc 역할
    *p = 10;

    std::cout << *p << std::endl;

    delete p;           //free 역할
    return 0;
}