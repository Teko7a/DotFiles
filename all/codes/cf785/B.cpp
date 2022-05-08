/* HOW B ? 2022-05-02 02:42:47 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  std::string s;
  std::cin >> s;

  int n = s.size(), len = s.size();

  static char * str = new char [200007];
  // scanf("%s", str + 1);
  std::strcpy(str + 1, s.data());

  std::array<int, 26> pos{};
  for (int i = 1; i <= n; ++i) {
    int si = str[i] - 'a';
    if (pos[si] != 0) {
      len = i - pos[si];
      break;
    }
    pos[si] = i;
  }

  for (int i = 1; i + len <= n; ++i) {
    if (str[i] != str[i + len]) {
      return std::cout << "NO\n", void();
    }
  }

  std::cout << "YES\n";
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

