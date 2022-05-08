/* HOW B ? 2022-05-06 00:02:55 */
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
  for (int i = n - 2; i >= 0; --i) {
    if (!a[i + 1]) {
      return std::cout << "-1\n", void();
    } else {
      while (a[i] >= a[i + 1]) {
        a[i] >>= 1;
        ans += 1;
      }
    }
  }
  std::cout << ans << '\n';
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

