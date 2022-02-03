#include <iostream>

int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();            //상수 레퍼런스
  std::cout << "c : " << c << std::endl;
  return 0;
}