/* HOW D ? 2022-05-02 22:54:56 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);

  for (auto &i : a) {
    std::cin >> i;
  }

  for (int i = n - 2; i >= 0; i -= 2) {
    std::cout << i << ' ' << i + 1 << '\n';
    if (a[i] > a[i + 1]) {
      std::swap(a[i], a[i + 1]);
    }
  }

  std::cout << "---\n";

  for (int i = 0; i <= n - 2; i += 2) {
    std::cout << i << ' ' << i + 1 << '\n';
    if (a[i] > a[i + 1]) {
      std::swap(a[i], a[i + 1]);
    }
  }

  std::cout << (std::is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
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
