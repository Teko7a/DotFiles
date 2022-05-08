/* HOW J ? 2022-04-27 13:13:11 */
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
static const int N = 1002;

int n, m;

static char mp[N][N];
static int onfire[N][N];
static int dist[N][N];
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

int main() {
  int tt;
  scanf("%d", &tt);
  for (int test = 1; test <= tt; ++test) {
    scanf("%d%d", &n, &m);

    memset(onfire, 0X3F, sizeof onfire);
    memset(dist, 0X3F, sizeof dist);

    std::queue<pii> fires;
    std::queue<pii> q;

    bool escaped = false;

    for (int i = 0; i < n; ++i) {
      scanf(" %[^\n]", mp[i]);
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == 'F') {
          fires.push(pii(i, j));
          onfire[i][j] = 1;
        } else if (mp[i][j] == 'J') {
          // jiangly I love you
          if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            escaped = true;
          } else {
            q.push(pii(i, j));
            dist[i][j] = 1;
          }
        }
      }
    }

    if (escaped) {
      puts("1");
      goto OUT;
    }

    // pre-process when the fires reach firstly.
    while (fires.size()) {
      pii t = fires.front();
      fires.pop();

      int x = t.first, y = t.second;

      for (int i = 0; i < 4; ++i) {
        int px = x + dx[i], py = y + dy[i];
        if (px < 0 || px >= n || py < 0 || py >= m) {
          continue;
        } else if (onfire[px][py] != 0X3F3F3F3F || mp[px][py] == '#') {
          continue;
        } else {
          fires.push(pii(px, py));
          onfire[px][py] = onfire[x][y] + 1;
        }
      }
    }

    // try to escape the maze.
    while (q.size()) {
      pii t = q.front();
      q.pop();

      int x = t.first, y = t.second;

      for (int i = 0; i < 4; ++i) {
        int px = x + dx[i], py = y + dy[i];

        if (px < 0 || px >= n || py < 0 || py >= m) {
          continue;
        } else if (mp[px][py] == '#' || mp[px][py] == 'F' 
            || dist[px][py] != 0X3F3F3F3F) {
          continue;
        } 

        dist[px][py] = dist[x][y] + 1;

        if (dist[px][py] > onfire[px][py]) {
          continue;
        }

        if (px == 0 || py == 0 || px == n - 1 || py == m - 1) {
          if (dist[px][py] < onfire[px][py]) {
            printf("%d\n", dist[px][py]);
            goto OUT;
          }
        }

        q.push(pii(px, py));
      }

    }

    puts("IMPOSSIBLE");
OUT:;
  }

  return 0 ^ 0;
}
