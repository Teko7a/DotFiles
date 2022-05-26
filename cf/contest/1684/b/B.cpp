#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;

  std::cout << a + b + c << ' '
            << b + c << ' '
            << c << '\n';
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
