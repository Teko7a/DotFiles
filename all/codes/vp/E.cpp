#include <bits/stdc++.h>

using i64 = long long; // <+>

static constexpr int P = 1E9 + 7;

// Z from jiangly
// assume -P <= x < 2P
int norm(int x) { return x >= P ? x - P : x < 0 ? x + P : x; }
template <class T> T power(T a, int b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int x = 0) : x(norm(x)) {}
  Z(i64 x) : x(norm(x % P)) {}
  int val() const { return x; }
  friend std::ostream &operator<<(std::ostream &os, const Z &x) {
    return os << x.val();
  }
  Z operator-() const { return Z(norm(P - x)); }
  Z inv() const {
    assert(x != 0);
    return power(*this, P - 2);
  }
  Z &operator*=(const Z &rhs) {
    x = i64(x) * rhs.x % P;
    return *this;
  }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
};

Z binom2(int n) {
  return 1LL * n * (n + 1) / 2;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> G(n);

  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    -- u, -- v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  Z ans = binom2(n) * binom2(n);
  std::vector<int> size(n);

  std::function<void(int, int)> dfs = [&](int u, int p) {
    size[u] = 1;
    for (auto &&to : G[u]) if (to != p) {
      dfs(to, u);
      size[u] += size[to];
    }
    Z cnt1 = binom2(size[u]), cnt2 = 1LL * size[u] * (n - size[u]);
    for (auto &&to : G[u]) if (to != p) {
      cnt1 -= binom2(size[to]);
    }

    ans -= (cnt1 + cnt2) * (cnt1 + cnt2) - cnt2 * cnt2;
  };

  dfs(0, -1);

  std::cout << ans / 2 << '\n';
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

