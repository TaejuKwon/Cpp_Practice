#include <iostream>
#include <string>

int main() {
    int t;
    while (true) {
        // std::cin.setf(std::ios_base::hex, std::ios_base::basefield);  두번째 인자  basefield로 내용 초기화, 첫번째 인자 hex 적용
        // std::cin >> t;
        std::cin >> std::hex >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();            // 플래그들을 초기화
                                         // std::cin.ignore(100, '\n'); 개행 문자가 나올 때까지 무시
        }
        if ( t == 1 ) break;
    }
}
// hex 와 같이, 스트림을 조작하여 입력 혹은 출력 방식을 바꿔주는 함수를 조작자라고 부름