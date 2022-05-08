#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> a(n + 1), b(n + 1);

  a[0] = b[0] = 0;

  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] = a[i - 1] + a[i];
  }

  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
    b[i] = b[i - 1] + b[i];
  }

  std::vector<i64> dp(n + 1, -1);

  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    if (dp[i] != -1) {
      for (int j = i + 1; j <= n; ++j) {
        if (a[j] - a[i] >= b[j] - b[i]) {
          dp[j] = std::max(dp[j], dp[i] + 1);
        }
      }
    }
  }

  std::cout << dp.back() << '\n';
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

