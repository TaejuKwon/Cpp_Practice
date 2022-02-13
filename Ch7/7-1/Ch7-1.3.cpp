#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();            // 플래그들을 초기화
            std::cin.ignore(100, '\n');  // 개행 문자가 나올 때까지 무시
        }
        if ( t == 1 ) break;
    }
}