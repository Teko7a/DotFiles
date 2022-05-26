#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  int ans = 0; // n - 1; // a.back();

  int m;
  std::cin >> m;
  std::vector<int> b(m);
  for (auto &i : b) {
    std::cin >> i;
    // ans = (ans - i + n) % n;
    ans = (ans + i) % n;
  }

  std::cout << a.at(ans) << '\n';
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
