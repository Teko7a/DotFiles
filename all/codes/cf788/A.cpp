/* HOW A ? 2022-05-06 22:35:21 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);

  int cnt = 0;

  for (auto &i : a) {
    std::cin >> i;
    cnt += i < 0;
  }

  if (std::is_sorted(a.begin(), a.end(), std::less<>())) {
    return std::cout << "YES\n", void();
  }

  std::transform(a.begin(), a.end(), a.begin(), [&](int n) { return std::abs(n); });
  std::transform(a.begin(), a.begin() + cnt, a.begin(), std::negate<>());

  if (std::is_sorted(a.begin(), a.end(), std::less<>())) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
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

