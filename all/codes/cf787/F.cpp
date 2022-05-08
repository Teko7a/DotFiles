/* HOW F ? 2022-05-06 18:38:45 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, k, x, y;
  std::cin >> n >> k >> x >> y;

  x -= 1, y -= 1;

  std::vector<int> a(k);
  for (auto &i : a) {
    std::cin >> i;
    i -= 1;
  }

  a.push_back(y);
  std::vector<std::vector<int>> G(n);

  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    u -= 1, v -= 1;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  std::vector<int> dep(n), pre(n, -1);
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto &&to : G[u]) if (to != pre[u]) {
      pre[to] = u;
      dep[to] = dep[u] + 1;
      self(self, to);
    }
  };

  dfs(dfs, x);

  int ans = 0;

  std::vector<bool> visited(n);
  visited[x] = true;

  for (auto &&p : a) {
    while (!visited[p]) {
      visited[p] = true;
      ans += 2;
      p = pre[p];
    }
  }

  ans -= dep[y];
  std::cout << ans << '\n';
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

