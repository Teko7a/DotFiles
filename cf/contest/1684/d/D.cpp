#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);

  i64 s = 1LL * n * k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    s += a[i];
    a[i] += i + 1;
  }

  std::sort(a.rbegin(), a.rend());

  s -= std::accumulate(a.begin(), a.begin() + k, 0LL);

  s -= 1LL * k * k - 1LL * k * (k + 1) / 2;

  std::cout << s << '\n';
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

