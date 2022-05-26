#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);

  for (auto &i : a) {
    std::cin >> i;
  }

  for (auto &i : b) {
    std::cin >> i;
  }

  // bool s1 = std::is_sorted(a.begin(), a.end(), std::less<int>());
  // bool s2 = std::is_sorted(b.begin(), b.end(), std::less<int>());
  //
  // if (s1 && s2) {
  //   return std::cout << "0\n", void();
  // } else if (s1 ^ s2) {
  //   return std::cout << "-1\n", void();
  // }

  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        if (b[j] >= b[j + 1]) {
          std::swap(b[j], b[j + 1]);
          ans.emplace_back(j + 1, j + 2);
        } else {
          return std::cout << "-1\n", void();
        }
      } else if (a[j] == a[j + 1]) {
        if (b[j] > b[j + 1]) {
          std::swap(b[j], b[j + 1]);
          ans.emplace_back(j + 1, j + 2);
        }
      } else {
        if (b[j] > b[j + 1]) {
          return std::cout << "-1\n", void();
        }
      }
    }
  }

  assert(std::is_sorted(a.begin(), a.end(), std::less<int>()));
  assert(std::is_sorted(b.begin(), b.end(), std::less<int>()));

  std::cout << (int)ans.size() << '\n';
  for (auto &[a, b] : ans) {
    std::cout << a << ' ' << b << '\n';
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
