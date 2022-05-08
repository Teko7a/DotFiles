/* HOW M ? 2022-04-27 21:36:35 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cassert>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <climits>

typedef std::pair<int, int> pii;

int n, m;

static const int N = 202;
static char mp[N][N];
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

static int d1[N][N], d2[N][N];

void bfs(int dist[][N], pii st) {
  std::queue<pii> q;
  q.push(st);

  int x = st.first, y = st.second;
  dist[x][y] = 0;

  while (q.size()) {
    pii t = q.front();
    q.pop();

    int x = t.first, y = t.second;
    for (int i = 0; i < 4; ++i) {
      int px = x + dx[i], py = y + dy[i];
      if (px < 0 || px >= n || py < 0 || py >= m || mp[px][py] == '#'
          || dist[px][py] != 0X3F3F3F3F) {
        continue;
      } else {
        dist[px][py] = dist[x][y] + 1;
        q.push(pii(px, py));
      }
    }
  }
}

int main() {

  while (~scanf("%d%d", &n, &m)) {
    pii Y, M;

    for (int i = 0; i < n; ++i) {
      scanf(" %[^\n]", mp[i]);
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == 'Y') {
          Y = pii(i, j);
        } else if (mp[i][j] == 'M') {
          M = pii(i, j);
        }
        d1[i][j] = d2[i][j] = 0X3F3F3F3F;
      }
    }

    bfs(d1, Y);
    bfs(d2, M);

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '@') {
          ans = std::min(ans, d1[i][j] + d2[i][j]);
        }
      }
    }

    printf("%lld\n", 11LL * ans);
  }

  return 0 ^ 0;
}
