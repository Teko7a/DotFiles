#include <bits/stdc++.h>

using i64 = long long; // <+>

template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

template <class Fun> struct y_combinator_result {
  Fun fun_;
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <class T> T randint(T a, T b) {
  return std::uniform_int_distribution<T>(a, b)(rng);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  auto X = 1LL;
  for (int i = 1; i <= 16; ++i) {
    X = std::lcm(X, i);
  }

  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0, x; j < m; ++j) {
      std::cin >> x;
      if ((i + j) % 2 == 1) {
        std::cout << X - 1LL * x * x * x * x;
      } else {
        std::cout << X;
      }
      std::cout << " \n"[j + 1 == m];
    }
  }

  return 0 ^ 0;
}
