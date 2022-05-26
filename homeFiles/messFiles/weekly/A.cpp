
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  int cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    int M = std::max(a[i], a[i + 1]);
    int m = std::min(a[i], a[i + 1]);
    while ((1. * M) / (1. * m) > 2.) {
      m *= 2;
      cnt += 1;
    }
  }

  std::cout << cnt << '\n';
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
