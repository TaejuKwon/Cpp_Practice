#include <iostream>
#include <cstring>
class Complex {
    private:
        double real, img;

        double get_number(const char* str, int from, int to) const;
    
    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);
        
        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        friend Complex operator+(const Complex& a, const Complex& b);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "( " << c.real << " , " << c.img << " ) ";
    return os;
}


Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

double Complex::get_number(const char* str, int from, int to) const{
    bool minus = false;
    if (from > to) return 0;

    if(str[from] == '-') minus = true;
    if(str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) & integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.') {
            integer_part = false;
        }
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else {break;}
    }

    if (minus) num *= -1.0;

    return num;
}
Complex::Complex(const char* str) {
    // 입력 받은 문자열 분석하여 real 부분과 img 부분을 찾아야 함
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 'i' 위치 찾기
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    } 

    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    std::cout << "a의 값은 : " << a << " 이다. " << std::endl;
}