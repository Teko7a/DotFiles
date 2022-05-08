#include <bits/stdc++.h>

void solve() {
  int p;
  std::cin >> p;

  int n = 1 << p;
  std::vector<std::vector<std::pair<int, int>>> G(n);

  for (int i = 0, u, v; i < n - 1; ++i) {
    std::cin >> u >> v;
    u -= 1, v -= 1;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
  }

  std::vector<int> a(n), b(n - 1);

  a[0] = n;

  auto dfs = [&](auto &&self, int u, int p, bool v) -> void {
    for (auto &&[to, j] : G[u]) if (to != p) {
      if (v) {
        std::tie(b[j], a[to]) = std::tuple{to ^ n, to};
      } else {
        std::tie(b[j], a[to]) = std::tuple{to, to ^ n};
      }
      self(self, to, u, v ^ 1);
    }
  };

  dfs(dfs, 0, -1, 1);

  std::cout << "1\n";
  std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt --) {
    solve();
  }

  return 0 ^ 0;
}

