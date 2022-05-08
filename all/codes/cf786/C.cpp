/* HOW C ? 2022-05-02 22:45:11 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::string s, t;
  std::cin >> s >> t;

  if (std::count(t.begin(), t.end(), 'a') != 0) {
    if (t == "a") {
      return std::cout << "1\n", void();
    } else {
      return std::cout << "-1\n", void();
    }
  }

  int n = s.size();

  std::cout << (1LL << n) << '\n';
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

