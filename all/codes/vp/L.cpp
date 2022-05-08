#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<i64> a(n);

  for (auto &i : a) {
    std::cin >> i;
    i *= -1;
  }

  int l = 0, r = 2E9;
  while (l < r) {
    i64 mid = (l + r) / 2;
    bool check = [&](i64 mid) {
      std::priority_queue<i64> pq(a.begin(), a.begin() + k);
      for (int i = k; i < n; ++i) {
        auto h = -pq.top();
        pq.pop();

        if (mid < h) {
          return false;
        } else {
          mid += h;
          pq.push(a[i]);
        }
      }

      while ((int)pq.size()) {
        auto h = -pq.top();
        pq.pop();
        if (mid < h) {
          return false;
        } else {
          mid += h;
        }
      }
      return true;
    }(mid);

    if (check) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  std::cout << l << '\n';
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

