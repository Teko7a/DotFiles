#include <bits/stdc++.h>

using i64 = long long; // <+>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = i * 2; j <= n; j += i) {
      a[j] = i;
    }
  }

  std::sort(a.begin(), a.end());

  int res = 0;
  for (int i = 2; i <= n; ++i) {
    res = std::max(res, a[i]);
    std::cout << res << ' ';
  }

  return 0 ^ 0;
}
