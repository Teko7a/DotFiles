#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, k, x, y;
  std::cin >> n >> k >> x >> y;

  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  int M = *std::max_element(a.begin(), a.end());

  i64 basic = 1LL * k * (x - y);

  int l = 0, r = 2E9;

  while (l < r) {
    i64 mid = (l + r) / 2;
    i64 damage = mid <= k ? mid * x : mid * y + basic;
    if (damage >= M) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  std::cout << l << '\n';
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


