/* HOW A ? 2022-05-02 22:35:35 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int a, b;
  std::cin >> a >> b;

  if (b % a != 0 || b < a) {
    return std::cout << "0 0\n", void();
  }

  std::cout << 1 << ' ' << (b / a) << '\n';
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

