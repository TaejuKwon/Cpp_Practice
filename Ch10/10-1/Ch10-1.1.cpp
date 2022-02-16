#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);  // 맨 뒤에 10 추가
    vec.push_back(20);  // 맨 뒤에 20 추가
    vec.push_back(30);  // 맨 뒤에 30 추가
    vec.push_back(40);  // 맨 뒤에 40 추가

    // 전체 벡터 출력
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout <<"3번째 원소 :: " << *itr << std::endl;
}