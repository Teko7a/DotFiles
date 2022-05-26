#include <bits/stdc++.h>

using i64 = long long; // <+>

using u64 = unsigned long long;

struct custom_hash {
  // http://xorshift.di.unimi.it/splitmix64.c
  static u64 splitmix64(u64 x) {
    x += 0X9E3779B97F4A7C15;
    x = (x ^ (x >> 30)) * 0XBF58476D1CE4E5B9;
    x = (x ^ (x >> 27)) * 0X94D049BB133111EB;
    return x ^ (x >> 31);
  }
  size_t operator()(u64 x) const {
    static const u64 RDM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + RDM);
  }
};

static constexpr int mod = 1E9 + 7;

void solve() {
  int n;
  std::cin >> n;

  std::unordered_map<i64, i64, custom_hash> dp;

  dp[0] = 1;

  i64 s = 1, lv = 0, x;
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    i64 prefix = s - dp[lv];
    s = ((s + prefix) % mod + mod) % mod;
    dp[lv] = ((dp[lv] + prefix) % mod + mod) % mod;
    lv -= x;
  }

  std::cout << s << '\n';
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
