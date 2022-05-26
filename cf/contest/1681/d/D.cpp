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
    static const u64 RDM = std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + RDM);
  }
};
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  i64 x;
  std::cin >> n >> x;

  if (x == 1) {
    return std::cout << (n == 1 ? "0\n" : "-1\n"), 0 ^ 0;
  }

  std::bitset<10> v{};
  auto set = [&](i64 x) {
    v.reset();
    for (auto c : std::to_string(x)) {
      v[c - '0'] = 1;
    }
  };

  std::queue<i64> q;
  std::unordered_map<i64, int, custom_hash> mp;

  q.push(x);

  while (q.size()) {
    auto x = q.front();
    q.pop();

    if ((int)std::to_string(x).size() == n) {
      return std::cout << mp[x] << '\n', 0 - 0;
    }

    set(x);

    for (int i = 9; i >= 2; --i) {
      if (v.test(i)) {
        if (!mp.count(x * i)) {
          int len = (int)std::to_string(x * i).size();
          if (len == n) {
            return std::cout << mp[x] + 1 << '\n', 0 - 0;
          } else if (len > n) {
            continue;
          }
          q.push(x * i);
          mp[x * i] = mp[x] + 1;
        }
      }
    }
  }

  std::cout << "-1\n";

  return 0 ^ 0;
}
