#include <iostream>

// A function that prints whatever you give it, as long as it knows how to
// convert it to a a string.
template <typename... Ts> void Print(Ts... ts) {
  ((std::cout << std::forward<Ts>(ts) << " "), ...);
  std::cout << "\n";
}

int main(int argc, char **argv) {
  Print(argv[0], argv[1], 10, 10.0f, 10.0l);
  return 0;
}