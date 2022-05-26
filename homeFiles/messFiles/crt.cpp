#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long i64;

const int maxn = 100;
const int maxd = 1e7 + 6e6;
const i64 INF = 0X7FFFFFFFFFFFFFFF;

namespace ExtendGcd {

typedef long long ll;

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extend_gcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else
    x = 1, y = 0;
  return d;
}

} // namespace ExtendGcd

namespace CRT {

typedef long long ll;

ll quick_mul(ll a, ll b, ll mod) {
  ll res = 0;
  while (a) {
    if (a & 1)
      res = (res + b) % mod;
    b = 2 * b % mod;
    a >>= 1;
  }
  return res;
}

ll inv(ll t, ll p) {
  ll x, y, d;
  d = ExtendGcd::extend_gcd(t, p, x, y);
  return d == 1 ? (x % p + p) % p : -1;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return b / gcd(a, b) * a; }

// x = a(mod m)
ll solve(const vector<ll> &a, const vector<ll> m) {
  ll M = 1, res = 0;
  for (int i = 0; i < m.size(); ++i)
    M = lcm(M, m[i]);
  for (int i = 0; i < a.size(); ++i) {
    ll Mi = M / m[i];
    ll ti = inv(Mi, m[i]);
    res = (res + quick_mul(quick_mul(a[i], ti, M), Mi, M)) % M;
  }
  return res;
}

} // namespace CRT

i64 quick_pow(i64 base, i64 index, i64 p) {
  i64 res = 1;
  while (index) {
    if (index & 1)
      res = res * base % p;
    base = base * base % p;
    index >>= 1;
  }
  return res;
}

i64 cal(i64 n, i64 m, i64 p) {
  i64 res = 0;
  for (i64 i = n; i; i /= p)
    res += i / p;
  for (i64 i = m; i; i /= p)
    res -= i / p;
  for (i64 i = n - m; i; i /= p)
    res -= i / p;
  return res;
}

i64 fac[maxd + 5];

i64 solve(i64 n, i64 p, i64 pk) {
  if (n == 0)
    return 1;
  i64 ans = quick_pow(fac[pk], n / pk, pk) * fac[n % pk] % pk;
  return ans * solve(n / p, p, pk) % pk;
}

i64 C(i64 n, i64 m, i64 p, i64 pk) {
  if (n < m)
    return 0;
  fac[0] = 1;
  for (int i = 1; i <= pk; ++i) {
    fac[i] = fac[i - 1];
    if (i % p != 0)
      fac[i] = fac[i] * i % pk;
  }
  i64 f1 = solve(n, p, pk), f2 = solve(m, p, pk), f3 = solve(n - m, p, pk);
  return f1 * CRT::inv(f2, pk) % pk * CRT::inv(f3, pk) % pk;
}

i64 n, m, p, D, res;
vector<i64> A, M;
int prime[maxn + 5], pk[maxn + 5], ptimes[maxn + 5], cnt;
i64 k = INF;

int main() {
  scanf("%lld %lld %lld", &n, &m, &p);
  D = p;
  int block = sqrt(p);
  for (int i = 2; i <= block && D > 1; ++i) {
    if (D % i == 0) {
      cnt += 1;
      int u = 1, k1 = 0;
      while (D % i == 0) {
        D /= i;
        u *= i;
        k1 += 1;
      }
      prime[cnt] = i, pk[cnt] = u, ptimes[cnt] = k1;
      i64 k2 = cal(n, m, i);
      assert(k1 != 0);
      k = min(k, k2 / k1);
    }
  }
  if (D > 1) {
    cnt += 1;
    prime[cnt] = D, pk[cnt] = D, ptimes[cnt] = 1;
    i64 c = cal(n, m, D);
    k = min(k, c);
  }
  for (int i = 1; i <= cnt; ++i) {
    i64 sum = cal(n, m, prime[i]);
    i64 ans = C(n, m, prime[i], pk[i]);
    ans = ans * quick_pow(prime[i], sum - k * ptimes[i], pk[i]) % pk[i];
    ans = ans * CRT::inv(quick_pow(p / pk[i], k, pk[i]), pk[i]) % pk[i];
    A.push_back(ans);
    M.push_back(pk[i]);
  }
  res = CRT::solve(A, M);
  printf("%lld\n", res);
  return 0;
}
