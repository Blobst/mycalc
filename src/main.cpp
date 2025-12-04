#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

bool calcIsRunning = true;

#include <bits/stdc++.h>

#include "calc.hpp"

/*------------------ HIDDEN PASSWORD INPUT ------------------*/
#ifdef _WIN32
#include <conio.h>
std::string inputHidden() {
  std::string pw;
  char ch;
  while ((ch = _getch()) != '\r') {  // Enter
    if (ch == '\b' && !pw.empty()) {
      pw.pop_back();
      std::cout << "\b \b";
    } else {
      pw.push_back(ch);
      std::cout << "*";
    }
  }
  std::cout << "\n";
  return pw;
}
#else
#include <termios.h>
#include <unistd.h>
std::string inputHidden() {
  termios oldt{}, newt{};
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  std::string pw;
  std::getline(std::cin, pw);

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return pw;
}
#endif

/*================= PASSWORD PROTECTED =================*/
std::string PASSWORD = "admin";    // change it here
std::string ENC_KEY = "mysecret";  // encryption key

bool passwordPrompt(std::string reason) {
  std::println(YELLOW "{} - Enter password:" RESET, reason);
  std::print("> ");
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return inputHidden() == PASSWORD;
}

std::string key = "mysecretkey";

// XOR encryption/decryption
std::string xorCrypt(const std::string& text) {
  std::string out = text;
  for (size_t i = 0; i < text.size(); i++)
    out[i] = text[i] ^ key[i % key.size()];
  return out;
}

void saveEncrypted(double result) {
  std::ifstream in("hist.txt", std::ios::binary);
  std::string existing((std::istreambuf_iterator<char>(in)),
                       std::istreambuf_iterator<char>());
  in.close();

  std::string plain = xorCrypt(existing);  // decrypt old
  plain += std::to_string(result) + "\n";  // add new entry

  std::ofstream out("hist.txt", std::ios::binary | std::ios::trunc);
  out << xorCrypt(plain);  // encrypt whole file again
}

void readDecrypted() {
  std::ifstream in("hist.txt", std::ios::binary);
  std::string encrypted((std::istreambuf_iterator<char>(in)),
                        std::istreambuf_iterator<char>());
  in.close();

  std::string plain = xorCrypt(encrypted);
  std::println("--- Decrypted History ---");
  std::print("{}", plain);
  std::println("-------------------------");
}

/*================= CLEAR HISTORY (ASK PW) =================*/
void cache_settings() {
  int set;
  system("cls||clear");

  std::println(BLUE "Cache Settings" RESET);
  std::println("1. Clear History");
  std::print("> ");
  std::cin >> set;

  if (set == 1) {
    system("cls||clear");
    if (passwordPrompt("Clear history")) {
      std::ofstream("hist.txt", std::ios::trunc);
      std::println(GREEN "History wiped successfully." RESET);
    } else
      std::println(RED "Wrong password. Cancelled." RESET);
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  return;
}

/*================= ANIMATION =================*/
void loading() {
  std::print(BLUE "Calculating" RESET);
  for (int i = 0; i < 3; i++) {
    std::print(".");
    std::this_thread::sleep_for(std::chrono::milliseconds(350));
  }
  std::println();
}

/*===================== MAIN ====================*/
int main() {
  double a, b, result{};
  char op;
  calc::Calculator calculator;

  while (calcIsRunning) {
    system("cls||clear");
    std::println(BLUE "+-*/ My Cool Calculator /*-+" RESET);
    std::println(RED "Operators: + - * /   r=read   c=settings   q=quit" RESET);

    std::print(YELLOW "Enter 2 numbers: " RESET);
    std::cin >> a >> b;

    std::print(GREEN "Enter operator: " RESET);
    std::cin >> op;

    switch (op) {
      case '+':
        result = calculator.add(a, b);
        break;
      case '-':
        result = calculator.sub(a, b);
        break;
      case '*':
        result = calculator.mul(a, b);
        break;
      case '/':
        result = calculator.div(a, b);
        break;
      case 'r':
        readDecrypted();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        continue;
      case 'c':
        cache_settings();
        continue;
      case 'q':
        calcIsRunning = false;
        continue;
      default:
        std::println(RED "Invalid operator." RESET);
        continue;
    }

    loading();
    std::println(RED "Result: {}" RESET, result);
    saveEncrypted(result);
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
  }
  return 0;
}
