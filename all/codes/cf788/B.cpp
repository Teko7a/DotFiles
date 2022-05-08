/* HOW B ? 2022-05-06 23:11:41 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::string s;

  std::cin >> n >> s;

  int k;
  std::cin >> k;

  std::bitset<26> S;

  for (int i = 0; i < k; ++i) {
    char ch;
    std::cin >> ch;
    S[ch - 'a'] = true;
  }

  int ans = 0;
  for (int i = 0, l = -1, r = 0; i < n; ++i) {
    if (S.test(s[i] - 'a')) {
      std::tie(l, r) = std::tuple{r, i};
      ans = std::max(ans, r - l);
    }
  }

  std::cout << ans << '\n';
}

// void solve() {
//   int n;
//   std::string s;
//
//   std::cin >> n >> s;
//
//   int k;
//   std::cin >> k;
//
//   std::set<int> S;
//
//   for (int i = 0; i < k; ++i) {
//     char ch;
//     std::cin >> ch;
//     S.insert(ch);
//   }
//
//   int ans = 0;
//   for (int i = 0, l = -1, r = 0; i < n; ++i) {
//     if (S.count(s[i])) {
//       std::tie(l, r) = std::tuple{r, i};
//       ans = std::max(ans, r - l);
//     }
//   }
//
//   std::cout << ans << '\n';
// }

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt --) {
    solve();
  }

  return 0 ^ 0;
}

