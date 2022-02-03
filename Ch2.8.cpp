#include <iostream>

int function() {
    int a = 5;
    return a;
}

int main() {
    const int& c = function();              // 상수 레퍼런스로 리턴 받으면 해당 값이 레퍼런스가 사라질 때까지 사라지지 않고 연장됨
    std::cout << "c : " << c << std::endl;
    return 0;

}