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

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), tree(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  y_combinator([&](auto dfs, int l, int r, int d) -> void {
    if (l > r) {
      return;
    }
    int u = std::max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
    tree[u] = d;
    dfs(l, u - 1, d + 1);
    dfs(u + 1, r, d + 1);
  })(0, n - 1, 0);

  for (auto &i : tree) {
    std::cout << i << ' ';
  }

  std::cout << '\n';
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
