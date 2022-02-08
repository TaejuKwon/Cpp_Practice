#include <iostream>
#include <string.h>

class MyString {
    char* string_content;   // 문자열 데이터를 가리키는 포인터
    int string_length;
    int memory_capacity;    // 현재 할당된 용량

    public:
        // 문자 하나로 생성
        MyString(char c);

        // 문자열로부터 생성
        MyString(const char* str);

        // 복사 생성자
        MyString(const MyString& str);

        ~MyString();

        int length() const;  
        int capacity() const;
        void reserve(int size);    
        // 할당할 문자열의 크기를 미리 예약해 놓는 reserve 함수   

        void print() const;
        void println() const;
        // 값을 읽기만 하므로, (내부 변수의 내용을 바꾸지 않음) -> const

        MyString& assign(const MyString& str);
        MyString& assign(const char* str);

        char at(int i) const;

        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, char c);
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    
}
MyString::~MyString() {delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        // 이 경우엔 다시 할당을 해주어야 한다
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        // 이 경우엔 다시 할당을 해주어야 한다
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++) {
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }

    // 만약 예약하려는 size가 현재 capacity 보다 작다면
    // 아무것도 안해도 된다
}   
char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return NULL;
        // i가 허용되는 범위를 초과한다면 NULL을 리턴
    }
    else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    // abc -> insert(1, "d") -> adbc

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length) {return* this;}

    if (string_length + str.string_length > memory_capacity) {
        // 새롭게 동적으로 할당
        memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char [memory_capacity];

        // insert 되는 부분 직전까지의 내용을 복사
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
    }
}

int main() {
    MyString str1("very very very long string");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String Length : " << str1.length() << std::endl;
    str1.println();

}
