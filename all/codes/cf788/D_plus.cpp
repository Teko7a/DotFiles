#include <bits/stdc++.h>

using i64 = long long; // <+>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt;
  for (std::cin >> tt; tt != 0; tt -= 1) {
    int n;
    std::cin >> n;

    i64 l = 0, r = 100'000;
    while (l + 1 < r) {
      i64 mid = (l + r) / 2;
      i64 x = mid / 3, y = (mid + 1) / 3, z = (mid + 2) / 3;
      if (2LL * (x * y + y * z + x * z) >= n) {
        r = mid;
      } else {
        l = mid;
      }
    }

    std::cout << r << '\n';
  }

  return 0 ^ 0;
}
