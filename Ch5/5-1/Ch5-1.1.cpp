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

        MyString& erase(int loc, int num);

        int find(int find_from, const MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;

        int compare(const MyString& str) const;
        bool operator==(MyString& str);
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
        return 0;
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

        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char [memory_capacity];

        // insert 되는 부분 직전까지의 내용을 복사
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }



    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < str.string_length; i++) {
        string_content[i + loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // loc 의 앞부터 시작해서 num 문자를 지운다
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
    // 생각하면 됩니다.

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1;  // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString& str) const {



    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        
        else if (string_content[i] < str.string_content[i])
            return -1;
    }


    if (string_length == str.string_length) {return 0;}

    else if (string_length > str.string_length)
        return 1;
    
    return -1;
}
bool MyString::operator==(MyString& str) {
    return !compare(str);   // str과 같으면 compare에서 0을 리턴
}
int main() {
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");

    if (str1 == str2) {
        std::cout << "str1와 str2는 같다." << std::endl;
    }
    else {
        std::cout << "str1와 str2는 다르다." << std::endl;
    }

    if (str2 == str3) {
        std::cout << "str2와 str3는 같다." << std::endl;
    }
    else {
        std::cout << "str2와 str3는 다르다." << std::endl;
    }
}