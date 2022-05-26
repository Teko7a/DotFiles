#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::string s;

  std::cin >> n >> s;

  int o = std::count(s.begin(), s.end(), '1');
  if (!o || o & 1) {
    return std::cout << "NO\n", void();
  }

  std::vector<std::pair<int, int>> ans, chain;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      int pos = i;
      while (s[(pos + 1) % n] == '0') {
        int nxt = (pos + 1) % n;
        ans.emplace_back(pos, nxt);
        pos = nxt;
      }
      chain.emplace_back(i, pos);
    }
  }

  for (int i = 1; i < (int) chain.size(); ++i) {
    ans.emplace_back(chain[0].second, chain[i].second);
  }

  std::cout << "YES\n";

  for (auto &[s, e] : ans) {
    std::cout << s + 1 << ' ' << e + 1 << '\n';
  }
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
