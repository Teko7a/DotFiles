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

template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  auto g = multivector<int>(n, 0, 0);

  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  std::vector<int> size(n, 0);
  std::vector<i64> seek(n, 0);

#define CON(N) (1LL * (N) * (N - 1) / 2)
  y_combinator([&](auto dfs, int u, int p) -> void {
    size[u] = 1;
    for (auto &&s : g[u]) {
      if (s != p) {
        dfs(s, u);
        size[u] += size[s];
        seek[u] += CON(size[s]);
      }
    }
    seek[u] += CON(n - size[u]);
  })(0, -1);

  int q;
  std::cin >> q;

  i64 ans = 0;

  for (int x; q-- && std::cin >> x; std::cout << ans << '\n') {
    x -= 1;
    ans = CON(n);
    ans -= seek[x];
  }

  return 0 ^ 0;
}
