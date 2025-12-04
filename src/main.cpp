#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <bits/stdc++.h>

#include "calc.hpp"

void clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void loading() {
  std::print(BLUE "Calculating" RESET);
  for (int i = 0; i < 3; i++) {
    std::print(".");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
  }
  std::println();
}

int main() {
  double a, b;
  double result{};  // Translates to double result = 0.0;
  char op;

  clear();
  std::println(BLUE "+-*/ My Cool Calculator /*-+" RESET);
  std::println(RED "Supported operators: + , - , / , * , or q to quit" RESET);

  std::print(
      YELLOW
      "Enter 2 numbers: " RESET);  // Numbers added by a space e.g. 20 1 not 201
  std::cin >> a >> b;

  std::print(GREEN "Enter a operator or (q to quit): " RESET);
  std::cin >> op;

  if (op == 'q' || op == 'Q') {
    std::exit(0);  // exits the program with error code 0 which means success
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
      result = calc::div(a, b);  // builtin zero division warning
      break;
    default:
      std::println("Thats not an operator...");
  }

  loading();
  std::print(RED "Result: {}\n" RESET, result);
  return 0;
}
