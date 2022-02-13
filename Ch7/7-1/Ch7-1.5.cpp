// 스트림 버퍼
// 스트림이라 하면 그냥 쉽게 말해서 문자들의 순차적인 나열
// streambuf 클래스는 스트림에 대한 가장 기본적인 제어를 담당
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (이 때는 움직이지 않음)
    // 문자열의 경우 공백문자가 나오기 전까지만 읽어들이기 때문
    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "두번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;
}