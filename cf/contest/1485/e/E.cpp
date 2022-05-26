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

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> d(n);
  auto g = multivector<int>(n, 0, 0);

  for (int i = 1, u; i < n; ++i) {
    std::cin >> u;
    u -= 1;
    g[u].push_back(i);
    g[i].push_back(u);
  }

  for (int i = 1; i < n; ++i) {
    std::cin >> d[i];
  }

  std::vector<int> p(n, -1), dep(n);

  y_combinator([&](auto dfs, int u) -> void {
    for (auto &&v : g[u]) {
      if (v != p[u]) {
        dep[v] = dep[u] + 1;
        p[v] = u;
        dfs(v);
      }
    }
  })(0);

  int depth = *std::max_element(dep.begin(), dep.end());

  auto G = multivector<int>(depth + 1, 0, 0);

  for (int i = 0; i < n; ++i) {
    G[dep[i]].push_back(i);
  }

  std::vector<i64> dp(n);
  for (int i = depth; i >= 0; --i) {
#define inf 1E18
    i64 m = inf, M = -inf;
    int rm = 1E9, rM = -1E9;
    for (auto &&u : G[i]) {
      rm = std::min(rm, d[u]);
      rM = std::max(rM, d[u]);
      for (auto &&v : g[u]) {
        if (v != p[u]) {
          m = std::min(m, d[u] - dp[v]);
          M = std::max(M, d[u] + dp[v]);
        }
      }
    }

    m = std::min<i64>(m, rm);
    M = std::max<i64>(M, rM);

    for (auto &&u : G[i]) {
      dp[u] = std::max(d[u] - m, M - d[u]);
      for (auto &&v : g[u]) {
        if (v != p[u]) {
          auto ans = std::max(d[u] - rm, rM - d[u]);
          dp[u] = std::max(dp[u], dp[v] + ans);
        }
      }
    }
  }

  std::cout << dp.front() << '\n';
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
