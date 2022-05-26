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

void solve() {
  int n;
  std::cin >> n;

  std::unordered_map<int, int, custom_hash> mp;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    mp[x] += 1;
  }

  std::vector<int> a;
  for (auto &[k, v] : mp) {
    a.push_back(v);
  }

  std::sort(a.rbegin(), a.rend());

  int ans = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    ans = std::max(ans, (i + 1) * a[i]);
  }

  std::cout << n - ans << '\n';
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
