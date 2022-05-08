#include <bits/stdc++.h>

using i64 = long long; // <+>

static constexpr int mod = 1'000'000'007;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n), p(n);

  std::vector<bool> visited(n);

  for (auto &i : a) {
    std::cin >> i;
    i -= 1;
  }

  for (auto &i : b) {
    std::cin >> i;
    i -= 1;
  }

  for (int i = 0, d; i < n; ++i) {
    std::cin >> d;
    if (d != 0) {
      visited[a[i]] = visited[b[i]] = true;
    }
  }

  for (int i = 0; i < n; ++i) {
    p[a[i]] = b[i];
  }

  std::vector<bool> st(n);

  int ans = 1;

  for (int i = 0; i < n; ++i) {
    if (!st[i]) {
      int cnt = 0, flag = 0;
      for (int j = i; !st[j]; j = p[j]) {
        st[j] = true;
        cnt += 1;
        flag |= visited[j];
      }
      if (cnt != 1 && flag == false) {
        ans = 2LL * ans % mod;
      }
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
