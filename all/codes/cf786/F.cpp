/* HOW ff ? 2022-05-03 13:32:52 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<bool> possessed(n * m);

  int cnt = 0, o = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      std::cin >> ch;
      if (ch == '*') {
        if (possessed[cnt]) {
          o += 1;
        }
        cnt += 1;
        possessed[j * n + i] = 1;
        if (j * n + i < cnt) {
          o += 1;
        }
      }
    }
  }

  for (int x, y; q != 0; --q) {
    std::cin >> x >> y;
    int i = -- y * n + -- x;

    if (possessed[i]) {
      if (i < cnt) {
        o -= 1;
      }
      cnt -= 1;
      possessed[i].flip();
      if (possessed[cnt]) {
        o -= 1;
      }
    } else {
      if (possessed[cnt]) {
        o += 1;
      }
      cnt += 1;
      possessed[i].flip();
      if (i < cnt) {
        o += 1;
      }
    }

    std::cout << cnt - o << '\n';
  }

  return 0 ^ 0;
}

