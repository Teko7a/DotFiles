/* HOW A ? 2022-05-02 02:03:59 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::string s;
  std::cin >> s;

  int ans = 0;
  for (auto &ch : s) {
    ch -= 'a' - 1;
    ans += ch;
  }

  if (s.size() == 1) {
    return std::cout << "Bob " << ans << '\n', void();
  }

  if (s.size() & 1) {
    ans -= 2 * std::min(s[0], s.back());
    // (ans < 0) && (ans = ~ans + 1);
  }
  std::cout << "Alice " << ans << '\n';
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

