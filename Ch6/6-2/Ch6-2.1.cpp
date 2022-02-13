// C++ 에서 상속이란 것을 도입함으로써, 클래스 사이에 관계를 표현할 수 있게 되었음
// is-a, has-a 관계

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
        Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

        void what() { std::cout << s << std::endl; }
};

int main() {
    Base p;
    Derived c;

    std::cout << "=== 포인터 버전 ===" << std::endl;
    Base* p_c = &c;     // 업 캐스팅 (파생 클래스에서 기반 클래스로 캐스팅 하는 것)
    p_c->what();
    return 0;
}