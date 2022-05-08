/* HOW E ? 2022-05-03 07:58:39 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  auto C = [&](int n, int d = 2) {
    return (n + d - 1) / d;
  };

  std::vector<int> a(n);

  int m1 = INT_MAX, m2 = INT_MAX;

  for (auto &i : a) {
    std::cin >> i;
    if (i < m1) {
      std::tie(m1, m2) = std::tuple{i, m1};
    } else if (i < m2) {
      m2 = i;
    }
  }

  int ans = C(m1) + C(m2);

  for (int i = 0; i < n - 1; ++i) {
    int A = a[i], B = a[i + 1];
    ans = std::min(ans, std::max({ C(A), C(B), C(A + B, 3) }));
  }

  for (int i = 0; i < n - 2; ++i) {
    ans = std::min(ans, 1 + a[i] / 2 + a[i + 2] / 2);
  }

  std::cout << ans << '\n';

  return 0 ^ 0;
}

