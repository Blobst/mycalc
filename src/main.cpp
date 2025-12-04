#include <bits/stdc++.h>

#include "calc.hpp"

int main() {
  double a, b;
  double result{}; // Translates to double result = 0.0;
  char op;
  std::println("My Cool Calculator");
  std::print("Enter 2 numbers: "); // Numbers added by a space e.g. 20 1 not 201
  std::cin >> a >> b;

  std::print("Enter a operator or (q to quit): ");
  std::cin >> op;

  if (op == 'q' || op == 'Q') {
    std::exit(0); // exits the program with error code 0 which means success
  }

  switch (op) {
    case '+':
      result = calc::add(a, b);
      break;
    case '-':
      result = calc::sub(a, b);
      break;
    case '*':
      result = calc::mul(a, b);
      break;
    case '/':
      result = calc::div(a, b); // builtin zero division warning
      break;
    default:
      std::println("Thats not an operator...");
  }

  std::print("Result: {}\n", result);
  return 0;
}
