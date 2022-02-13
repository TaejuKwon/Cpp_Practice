// override
#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
        Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

        virtual void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
    std::string s;

    public:
        Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

        void what() override { std::cout << s << std::endl; }
        // Base의 what을 override 하므로, override 키워드를 통해 이를 명시함
};