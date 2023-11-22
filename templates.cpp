#include <iostream>

template <typename T> void Print(T value) { std::cout << value << "\n"; }

int main(int argc, char **argv) {
  Print(argv[0]);
  Print(argv[1]);
  Print(190);
  Print(20.0);
  return 0;
}