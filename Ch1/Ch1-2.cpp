#include <iostream>
using namespace std;

namespace {
int OnlyInThisFile() {}
int only_in_this_file = 0;

}

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;

  cout << "Hello, World!!" << endl;

  std::cout << "hi" << std::endl
            << "my name is "
            << "Psi" << std::endl;
  return 0;

}