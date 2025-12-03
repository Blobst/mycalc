#include <bits/stdc++.h>

int main() {
  bool calcIsRunning = true;
  double a, b;
  double result{};
  char op;

  while (calcIsRunning) {
    std::println("My Cool Calculator");
    std::print("Enter a number: ");
    std::cin >> a;

    std::print("Enter a another number: ");
    std::cin >> b;

    std::print("Enter a operator or (q to quit): ");
    std::cin >> op;

    if (op == 'q' || op == 'Q') {
      calcIsRunning = false;
      continue;
    }

    switch (op) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        result = a / b;
        break;
      default:
        std::println("Thats not an operator...");
    }

    std::print("Result: {}\n", result);

  }
  return 0;
}
