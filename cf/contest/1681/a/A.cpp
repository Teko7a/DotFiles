#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, m;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  std::cin >> m;
  std::vector<int> b(m);
  for (auto &i : b) {
    std::cin >> i;
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  if (a.back() >= b.back()) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
  }

  if (a.back() <= b.back()) {
    std::cout << "Bob\n";
  } else {
    std::cout << "Alice\n";
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
