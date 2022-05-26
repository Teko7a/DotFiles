#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  int ans = 0;

  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      ans += 1;
      i += 1;
    }
  }

  std::cout << ans << '\n';
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
