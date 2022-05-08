/* HOW E ? 2022-05-06 10:43:26 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n, k;
  std::string s;

  std::cin >> n >> k >> s;

  int M = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] - 'a' > k) {
      int l = s[i] - k + M, r = s[i];
      for (auto &c : s) {
        if (c >= l && c <= r) {
          c = l;
        }
      }
      break;
    }
    M = std::max(M, s[i] - 'a');
  }

  for (auto &i : s) {
    if (i <= 'a' + M) {
      i = 'a';
    }
  }

  std::cout << s << '\n';
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

