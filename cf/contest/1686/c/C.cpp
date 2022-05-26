#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);

  for (auto &i : a) {
    std::cin >> i;
  }

  if (n & 1) {
    return std::cout << "NO\n", void();
  }

  std::sort(a.begin(), a.end());
  std::vector<int> b(n);

  for (int i = 0; i < n; ++i) {
    b[i] = a[i / 2 + (i & 1 ? n / 2 : 0)];
  }

  // for (auto &i : b) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';

  bool flag = true;
  b.push_back(b.front());
  for (int i = 1; i < n; i += 2) {
    flag &= b[i - 1] < b[i] && b[i] > b[i + 1];
    if (flag == false) {
      break;
    }
  }

  if (flag) {
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      std::cout << b[i] << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "NO\n";
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
