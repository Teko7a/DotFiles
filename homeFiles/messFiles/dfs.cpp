#include <bits/stdc++.h>

using i64 = long long; // <+>

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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> res(n);

  y_combinator([&res](auto dfs, int n, int r) -> void {
    for (int j = 1; j <= n / 2; ++j) {
      if (j >= res[r - 1]) {
        std::tie(res[r], res[r + 1]) = std::tuple{j, n - j};
        for (int k = 1; k <= r + 1; ++k) {
          std::cout << res[k] << "+\n"[k == r + 1];
        }
        dfs(n - j, r + 1);
      }
    }
  })(n, 1);

  return 0 ^ 0;
}
