#include <bits/stdc++.h>

#include "calc.hpp"

int main() {
  double a, b;
  double result{};
  char op;
  std::println("My Cool Calculator");
  std::print("Enter 2 numbers: ");
  std::cin >> a >> b;

  std::print("Enter a operator or (q to quit): ");
  std::cin >> op;

  if (op == 'q' || op == 'Q') {
    std::exit(0);
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
      result = calc::div(a, b);
      break;
    default:
      std::println("Thats not an operator...");
  }

  std::print("Result: {}\n", result);
  return 0;
}
