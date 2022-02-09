#include <iostream>

class A {
    mutable int data_;          // mutable 키워드는 const 함수 안에서 해당 멤버 변수에 const가 아닌 작업을 할 수 있게 해준다.
                                // (const가 필요한 상황에서)
    public:
        A(int data) : data_(data) {}
        void DoSomething(int x) const {
            data_ = x;
        }

        void PrintData() const {std::cout << "data : " << data_ << std::endl; }

};


int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}