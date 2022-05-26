#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::array<int, 4> a{};

  for (auto &i : a) {
    std::cin >> i;
  }

  std::string s;
  std::cin >> s;

  int A = std::count(s.begin(), s.end(), 'A');
  if (A != a[0] + a[2] + a[3]) {
    return std::cout << "NO\n", void();
  }

  int n = (int)s.size();


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
