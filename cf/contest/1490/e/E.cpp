#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::pair<i64, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }

  std::sort(a.begin(), a.end());

  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;

    auto check = [&]() {
      i64 cur = 0;
      for (int i = 0; i < m; ++i) {
        cur += a[i].first;
      }

      for (int i = m; i < n; ++i) {
        if (cur < a[i].first) {
          return false;
        }
        cur += a[i].first;
      }

      return true;
    }();

    if (check) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  std::set<int> ans;
  for (int i = l - 1; i < n; ++i) {
    ans.insert(a[i].second);
  }

  std::cout << ans.size() << '\n';

  for (auto &i : ans) {
    std::cout << i << ' ';
  }

  std::cout << '\n';
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
