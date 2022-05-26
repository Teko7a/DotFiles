#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::string s;

  std::cin >> n >> s;

  int mid = n / 2, l = mid - 1;
  while (l >= 0 && s[mid] == s[l]) {
    l -= 1;
  }

  std::cout << (mid - l - 1) * 2 + (n & 1) << '\n';
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
