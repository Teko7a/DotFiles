#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);

  i64 s = 0;
  for (auto &i : a) {
    std::cin >> i;
    s += i;
  }

  bool flag = false;

  for (int i = 0; i < n; ++i) {
    if ((s - a[i]) == a[i] * (n - 1)) {
      flag = true;
      break;
    }
  }

  std::cout << (flag ? "YES\n" : "NO\n");
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
