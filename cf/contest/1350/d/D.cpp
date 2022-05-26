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

void solve() {
  int n;
  i64 k;

  std::cin >> n >> k;
  std::vector<i64> a(n);

  bool flag = false;
  for (auto &i : a) {
    std::cin >> i;
    i = i > k ? 2 : i < k ? 0 : 1;
    flag |= i == 1;
  }

  if (flag == false) {
    return std::cout << "no\n", void();
  } else if (n == 1) {
    return std::cout << "yes\n", void();
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j : std::set{i + 1, i + 1 + (i != n - 2)}) {
      if (a[i] > 0 && a[j] > 0) {
        return std::cout << "yes\n", void();
      }
    }
  }

  return std::cout << "no\n", void();
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt--) {
    solve();
  }

  return 0 ^ 0;
}
