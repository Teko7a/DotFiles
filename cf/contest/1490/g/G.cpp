#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, q;
  std::cin >> n >> q;

  i64 s = 0;
  std::vector<std::pair<i64, int>> p;

  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    s += x;
    if (!i || s > p.back().first) {
      p.emplace_back(s, i);
    }
  }

  for (i64 x; q --; std::cout << " \n"[!q]) {
    std::cin >> x;

    auto &b = p.back().first;
    if (s <= 0) {
      if (x > b) {
        std::cout << "-1";
      } else {
        std::cout << std::lower_bound(p.begin(), p.end(), std::pair{x, 0})->second;
      }
    } else {
#define CEIL(a, b) (a + b - 1) / b
      i64 r = std::max(0LL, CEIL(x - b, s));
      std::cout << std::lower_bound(p.begin(), p.end(), std::pair{x - r * s, 0})->second + r * n;
    }
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
