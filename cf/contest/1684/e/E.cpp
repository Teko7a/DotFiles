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
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  std::multiset<int, std::greater<>> S;
  std::unordered_map<int, int, custom_hash> mp;

  for (auto &i : a) {
    std::cin >> i;
    mp[i] += 1;
    S.insert(i);
  }

  int mex = 0, K = k;
  while (true) {
    if (!S.count(mex)) {
      if (K == 0) {
        break;
      } else {
        auto i = S.begin();
        if (*i < mex) {
          break;
        } else {
          S.erase(i);
          K -= 1;
        }
      }
    }
    mex += 1;
  }

  if (mex >= n) {
    return std::cout << "0\n", void();
  }

  std::vector<int> p;
  for (auto [k, v] : mp) {
    if (k > mex) {
      p.push_back(v);
    }
  }

  std::sort(p.begin(), p.end());

  int id = 0;
  while (id < (int)p.size() && k >= p[id]) {
    k -= p[id++];
  }

  std::cout << (int)p.size() - id << '\n';
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
