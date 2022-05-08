/* HOW B ? 2022-05-02 22:38:44 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  static bool initialized = false;
  static std::map<std::array<char, 2>, int> mp;
  if (!initialized) {
    initialized ^= 1;
    int idx = 1;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (i == j) {
          continue;
        } else {
          std::array<char, 2> c;
          c[0] = 'a' + i;
          c[1] = 'a' + j;
          mp[c] = idx ++;
        }
      }
    }
  }


  std::array<char, 2> c;
  for (auto &ch : c) {
    std::cin >> ch;
  }

  std::cout << mp[c] << '\n';
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

