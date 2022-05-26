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

  int n;
  std::cin >> n;

  std::vector<i64> a(n);

  for (auto &o : a) {
    std::cin >> o;
  }

  auto p(a);
  for (int i = 1; i < n; ++i) {
    p[i] = std::gcd(p[i - 1], p[i]);
  }

  i64 ans = 0;

  for (int i = 1; i < n; ++i) {
    ans = std::gcd(ans, std::lcm(a[i], p[i - 1]));
  }

  std::cout << ans << '\n';

  return 0 ^ 0;
}
