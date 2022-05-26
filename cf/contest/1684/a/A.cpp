#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::string s;
  std::cin >> s;

  auto pos = std::min_element(s.begin(), s.end());

  if (s.size() == 2) {
    std::cout << s[1] << '\n';
  } else {
    std::cout << *pos << '\n';
  }
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
