#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;

  std::array<int, 3> cnt{};

  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    cnt[x % 3] += 1;
  }

  int m = std::min({cnt[0], cnt[1], cnt[2]});

  for (auto &i : cnt) {
    i -= m;
  }

  int ans = 0;
  auto &[a, b, c] = cnt;

  while (!(a == b && b == c)) {
    ans += 1;
    auto M = std::max({a, b, c});
    if (a == M) {
      a -= 1, b += 1;
    } else if (b == M) {
      b -= 1, c += 1;
    } else {
      c -= 1, a += 1;
    }
  }

  std::cout << ans << '\n';
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
