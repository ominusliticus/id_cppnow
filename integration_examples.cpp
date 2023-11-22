#include <iostream>

#include "Integration.hpp"

double f(double x);
double g(double x, double y, double a, double b);
double h(double x);

int main() {
  std::cout << "Hi, Isabella!\n";
  std::cout << GausQuad(f, 0, 1, 1e-9, 5) << "\n";
  std::cout << GausQuad([](double x) { return x * x; }, 0, 1, 1e-9, 5) << "\n";

  std::cout << GausQuad(g, 0.0, 1.0, 1e-9, 5, 1.0, 10.0, 10.0) << "\n";
  std::cout << GausQuad(
                   [](double y, double a, double b) {
                     return GausQuad(g, 0, 1, 1e-9, 5, y, a, b);
                   },
                   0, 1, 1e-9, 5, 10, 10)
            << "\n";
  std::cout << GausQuad(
                   [](double a, double b) {
                     return GausQuad(
                         [](double y, double a, double b) {
                           return GausQuad(g, 0, 1, 1e-9, 5, y, a, b);
                         },
                         0, 1, 1e-9, 5, a, b);
                   },
                   0, 1, 1e-9, 5, 10)
            << "\n";
  return 0;
}

double f(double x) { return x * x; }

double g(double x, double y, double a, double b) {
  return (a * x + y * b) * (a * x + y * b);
}

double h(double x) { return 1.0 - 1.0 / x; }
