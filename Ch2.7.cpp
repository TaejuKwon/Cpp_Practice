int& function(int& a) {
    a = 5;
    return a;
}

// 인자로 받은 레퍼런스를 그대로 리턴

int main() {
    int b = 2;
    int c = function(b);
    return 0;
}