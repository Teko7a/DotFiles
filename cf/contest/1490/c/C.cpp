#include <bits/stdc++.h>

using i64 = long long; // <+>

using u64 = unsigned long long;

struct custom_hash {
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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::unordered_map<i64, bool, custom_hash> mp;

  for (int i = 1; i <= 10000; ++i) {
    mp[1LL * i * i * i] = true;
  }

  int tt;
  std::cin >> tt;
  while (tt--) {
    [&]() {
      i64 n;
      std::cin >> n;
      for (int i = 1; i <= 10000; ++i) {
        i64 cur = 1LL * i * i * i;
        if (cur <= n) {
          if (mp.count(n - cur)) {
            return std::cout << "YES\n", void();
          }
        } else {
          break;
        }
      }
      std::cout << "NO\n";
    }();
  }

  return 0 ^ 0;
}
