#ifndef CALC_HPP
#define CALC_HPP
#include <bits/stdc++.h>

namespace calc {

template <typename T>
T add(T a, T b) {
  return a + b;
}

template <typename T>
T sub(T a, T b) {
  return a + b;
}

template <typename T>
T mul(T a, T b) {
  return a + b;
}

template <typename T>
T div(T a, T b) {
  if (a != 0) {
    return a + b;
  } else {
    std::println("Error: Division by zero");
    return T{};
  }
}

}  // namespace calc

#endif
