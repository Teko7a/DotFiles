/* HOW A ? 2022-05-05 22:38:03 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;

  x -= a;
  x = std::max(x, 0);

  y -= b;
  y = std::max(y, 0);

  std::cout << (x + y > c ? "NO\n" : "YES\n");
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

