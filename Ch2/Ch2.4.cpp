#include <iostream>

int main() {
  int x;
  int& y = x;
  int& z = y;

  x = 1;
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

  y = 2;
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

  z = 3;                                                                        //y, z 모두 x의 참조자가 됨
  std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}