#include <iostream>

int main() {
  const int &ref = 4;           //상수 레퍼런스

  std::cout << ref << std::endl;
}