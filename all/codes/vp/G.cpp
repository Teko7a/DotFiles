#include <bits/stdc++.h>

using i64 = long long; // <+>

struct node {
  int l, r;
  i64 val;
  bool operator< (const node &_) const {
    return this->l < _.l;
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), w(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i];
  }

  i64 ans = -1;
  std::vector<node> val(n + 1);
  std::vector<i64> suffix(n + 2);

  auto sol = [&]() {
    std::sort(val.begin() + 1, val.end());
    suffix.back() = 0;
    for (int i = n; i; --i) {
      suffix[i] = std::max(suffix[i + 1], val[i].val);
    }
    for (int i = 1; i <= n; ++i) {
      node t{val[i].r, 0, 0};
      auto pos = std::upper_bound(val.begin() + 1, val.end(), t);
      if (pos != val.end()) {
        ans = std::max(ans, suffix[pos - val.begin() - 1 + 1] + val[i].val);
      }
    }
  };

  for (int i = 1; i <= n; ++i) {
    val[i] = {a[i], c[i], w[i]};
  }

  sol();

  for (int i = 1; i <= n; ++i) {
    val[i] = {b[i], d[i], w[i]};
  }

  sol();

  std::cout << ans << '\n';
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
