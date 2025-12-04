#ifndef CALC_HPP
#define CALC_HPP
#include <bits/stdc++.h>

namespace calc {

class Calculator {
 public:
  Calculator() = default;

  double add(double a, double b) const { return a + b; }
  double sub(double a, double b) const { return a - b; }
  double mul(double a, double b) const { return a * b; }

  double div(double a, double b) const {
    if (b == 0.0) {
      std::println("Error: Division by zero");
      return 0.0;
    }
    return a / b;
  }
};

}  // namespace calc

#endif
