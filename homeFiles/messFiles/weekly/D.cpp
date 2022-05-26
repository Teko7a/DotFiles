
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int x, y;
  std::cin >> x >> y;
  std::cout << std::max(0, x - 1) << ' ' << y << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }

  return 0 ^ 0;
}
