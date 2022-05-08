/* HOW D ? 2022-05-02 18:47:51 */
#include <bits/stdc++.h>

using i64 = long long; // <+>


static constexpr int P = 1'000'000'007;

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
  i64 b, q, y, c, r, z;
  std::cin >> b >> q >> y >> c >> r >> z;

  i64 lb = c + (z - 1) * r, lc = b + (y - 1) * q;

  if (r % q || (c - b) % q || c < b || lb > lc) {
    return std::cout << "0\n", void();
  } else if (c - r < b || lb + r > lc) {
    return std::cout << "-1\n", void();
  }

  Z ans = 0;
  for (i64 i = 1; i * i <= r; ++i) {
    if (r % i != 0) {
      continue;
    }
    if (std::lcm(i, q) == r) {
      ans += r / i * r / i;
    }
    if (i * i == r) {
      continue;
    }
    i64 t = r / i;
    if (std::lcm(t, q) == r) {
      ans += r / t * r / t;
    }
  }

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

