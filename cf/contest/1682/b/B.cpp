#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, p = INT_MAX;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] != i) {
      p &= a[i];
    }
  }

  std::cout << p << '\n';
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
