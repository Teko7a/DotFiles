#include <bits/stdc++.h>

using i64 = long long; // <+>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // a(n) = 2 * (n - 1)^2 / 3 if n==1 (mod 3), a(n) = 2 * n * (n - 2) / 3 otherwise.

  std::vector<int> a(100000);
  for (int i = 2; i <= 100001; ++i) {
    if (i % 3 == 1) {
      a[i - 2] = 2LL * (i - 1) * (i - 1) / 3;
    } else {
      a[i - 2] = 2LL * i * (i - 2) / 3;
    }
  }

  int tt;
  std::cin >> tt;
  while (tt --) {
    int n;
    std::cin >> n;
    std::cout << std::lower_bound(a.begin(), a.end(), n) - a.begin() + 1 << '\n';
  }

  return 0 ^ 0;
}

