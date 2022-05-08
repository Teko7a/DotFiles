/* HOW A ? 2022-04-29 17:51:45 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

using status = std::array<std::array<int, 4>, 4>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  status mp;

  std::pair<int, int> st;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i * 4 + j == 15) {
        continue;
      }
      std::cin >> mp[i][j];
      if (mp[i][j] == 'x') {
        st = {i, j};
      }
    }
  }

  std::queue<status> q;
  q.push(mp);

  std::map<status, status> visited;

  return 0 ^ 0;
}

