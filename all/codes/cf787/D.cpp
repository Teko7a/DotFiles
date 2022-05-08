/* HOW E ? 2022-05-06 08:57:23 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  std::vector<bool> leaf(n, 1);

  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    p[i] -= 1;
    if (p[i] != i) {
      leaf[p[i]] = false;
    }
  }

  std::cout << std::count(leaf.begin(), leaf.end(), 1) << '\n';

  std::vector<bool> visited(n);

  for (int i = 0; i < n; ++i) {
    if (leaf[i]) {
      std::stack<int> ans;
      for (int j = i; !visited[j]; j = p[j]) {
        visited[j] = true;
        ans.push(j + 1);
      }
      std::cout << (int) ans.size() << '\n';
      while (ans.size()) {
        std::cout << ans.top() << " \n"[ans.size() == 1];
        ans.pop();
      }
    }
  }

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

