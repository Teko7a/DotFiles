
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

void solve() {
  int n, m;
  std::cin >> n >> m;

  i64 cnt = 0;

  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    cnt += std::count(s.begin(), s.end(), '#');
  }

  std::cout << power<Z>(2, cnt) - (cnt == 1LL * n * m) << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }

  return 0 ^ 0;
}
