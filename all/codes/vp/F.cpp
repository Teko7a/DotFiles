#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  i64 n, k;
  std::cin >> n >> k;

  i64 ans = 0;
  for (k ++; k -- && n != 0; n -= (n + 1) / 2) {
    i64 res = ((n + 1) / 2) * ((n + 1) / 2);
    if (k == 0) {
      ans += 1LL * (n / 2) * (n / 2 + 1);
    }
    ans += res;
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


