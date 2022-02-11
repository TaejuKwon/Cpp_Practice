// 상속(inheritance)
#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
        Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

        void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
        // 참고로 기반 클래스의 생성자를 명시적으로 호출하지 않을 경우 기반 클래스의 디폴트 생성자가 호출됨
        Derived() : Base(), s("파생") {
            std::cout << "파생 클래스" <<  std::endl;

            // 기반 클래스의 what() 을 파생 클래스인 Derived 에서 사용 가능
            what();
        }
    void what() { std::cout << s << std::endl; }
};
int main() {
    std::cout << " === 기반 클래스 생성 === " << std::endl;
    Base p;

    std::cout << " === 파생 클래스 생성 === " << std::endl;
    Derived c;

    return 0;
}