// 파일 쓰기

#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 쓰기 준비
    // std::ofstream out("test.txt");
    std::ofstream out("test.txt", std::ios::app);

    std::string s;
    if (out.is_open()) {
        // out << "이걸 쓰자~";
        out << "덧붙이기";
    }
    return 0;
}