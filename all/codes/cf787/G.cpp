#include <bits/stdc++.h>

template<class T> inline void chmin(T &x, T y) { x = x < y ? x : y; }

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n), s(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }

  std::vector dp(n + 1, std::vector(m + 1, std::vector<int>(m + 1, 0X7F7F7F7F)));

  dp[0][0][m] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int mx = 0X7F7F7F7F;
      for (int k = m; k >= 0; --k) {
        chmin(mx, dp[i][j][k]);
        if (j + k <= m) {
          chmin(dp[i + 1][j + k][k], mx + std::abs(s[i + 1] - (j + k)));
        }
      }
    }
  }

  std::cout << *std::min_element(dp[n][m].begin(), dp[n][m].end()) << '\n';

  return 0 ^ 0;
}

