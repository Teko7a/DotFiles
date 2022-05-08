/* HOW C ? 2022-05-02 03:48:42 */
#include <bits/stdc++.h>

using i64 = long long; // <+>


static constexpr i64 P = 1'000'000'007;

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
  static bool initialized = false;
  static std::vector<int> palind;
  static const int N = 4E4 + 7;
  // static std::array<Z, N> dp{};
  static Z dp[N];
  if (!initialized) {
    initialized ^= 1;
    for (int i = 1; i <= N - 7; ++i) {
      auto s = std::to_string(i);
      if (s == std::string(s.rbegin(), s.rend())) {
        palind.push_back(i);
      }
    }

    dp[0] = 1;
    for (auto &&num : palind) {
      for (int i = 0; i + num <= N - 7; ++i) {
        dp[i + num] += dp[i];
      }
    }
  }

  int n;
  std::cin >> n;
  std::cout << dp[n] << '\n';
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

