// friend 키워드

class A {
    private:
        void private_func() {}
        int private_num;

        friend class B;

        friend void func();
};

class B {
    public:
        void b() {
            A a;

            // 비록 private 함수이지만, friend 덕분에 접근 가능
            a.private_func();
            a.private_num = 2;
        }
};


void func() {
    A a;


    a.private_func();
    a.private_num = 2;

}

int main() {}