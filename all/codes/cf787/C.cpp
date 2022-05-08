/* HOW C ? 2022-05-05 23:03:29 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::string s;
  std::cin >> s;

  int p1 = 0, p0 = s.size() - 1;

  for (int i = 0; i < (int) s.size(); ++i) {
    if (s[i] == '0') {
      p0 = i;
      break;
    }
  }

  for (int i = (int) s.size(); i >= 0; --i) {
    if (s[i] == '1') {
      p1 = i;
      break;
    }
  }

  // std::cout << "? " << p0 << ' ' << p1 << ' ' << 1 << '\n';
  std::cout << std::abs(p0 - p1 + 1) << '\n';
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

