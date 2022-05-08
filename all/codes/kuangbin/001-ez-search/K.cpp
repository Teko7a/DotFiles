/* HOW K ? 2022-04-27 16:34:49 */
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

static int maze[5][5];
static int dist[5][5];
static pii pre[5][5];
static std::vector<pii> path;

static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {1, -1, 0, 0};

void dfs(pii p) {
  path.push_back(p);
  int x = p.first, y = p.second;
  if (!x && !y) {
    return;
  } else {
    pii prev = pre[x][y];
    dfs(prev);
  }
}

int main() {

  static const int n = 5;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &maze[i][j]);
    }
  }
  
  std::queue<pii> q;
  q.push(pii(0, 0));
  memset(dist, 0X3F, sizeof dist);
  dist[0][0] = 0;

  while (q.size()) {
    pii t = q.front();
    q.pop();

    int x = t.first, y = t.second;
    for (int i = 0; i < 4; ++i) {
      int px = x + dx[i], py = y + dy[i];
      if (px < 0 || px >= n || py < 0 || py >= n) {
        continue;
      } else if (maze[px][py]) {
        continue;
      }
      if (dist[px][py] > dist[x][y] + 1) {
        dist[px][py] = dist[x][y] + 1;
        pre[px][py] = pii(x, y);
        q.push(pii(px, py));
      }
    }
  }

  dfs(pii(n - 1, n - 1));

  while (path.size()) {
    printf("(%d, %d)\n", path.back().first, path.back().second);
    path.pop_back();
  }

  return 0 ^ 0;
}
