/* HOW I ? 2022-04-25 14:31:11 */
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

struct node {
  int x, y, d;
  node() {
    x = y = d = 0;
  }
  node(int _x, int _y, int _d) {
    x = _x;
    y = _y;
    d = _d;
  }
};


static const int N = 11;

int n, m;
node arr[N * N];

static char mp[N][N];
static bool visited[N * N][N * N];
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

int bfs(node st, node ed) {
  int ans = -1;
  std::queue<node> q;

  q.push(st);
  q.push(ed);

  while (q.size()) {
    node t = q.front();
    q.pop();

    int x = t.x, y = t.y, d = t.d;
    ans = std::max(ans, d);

    for (int i = 0; i < 4; ++i) {
      int px = x + dx[i], py = y + dy[i];
      if (px < 0 || px >= n || py < 0 || py >= m) {
        continue;
      } else if (visited[px][py] || mp[px][py] != '#') {
        continue;
      } else {
        visited[px][py] = true;
        node nd = node(px, py, d + 1);
        q.push(nd);
      }
    }
  }

  return ans;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int test = 1; test <= tt; ++test) {
    printf("Case %d: ", test);

    scanf("%d%d", &n, &m);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      scanf(" %[^\n]", mp[i]);
      // cnt += std::count(mp[i], mp[i] + m, '#');
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '#') {
          arr[cnt] = node(i, j, 0);
          cnt += 1;
        }
      }
    }

    if (cnt == 0) {
      puts("-1");
      continue;
    } else if (cnt <= 2) {
      puts("0");
      continue;
    }

    int ans = INT_MAX;

    for (int i = 0; i < cnt; ++i) {
      for (int j = i + 1; j < cnt; ++j) {
        memset(visited, 0X00, sizeof visited);
        visited[arr[i].x][arr[i].y] = visited[arr[j].x][arr[j].y] = true;

        bool ok = false;
        int minimum = bfs(arr[i], arr[j]);

        for (int k = 0; k < n; ++k) {
          for (int l = 0; l < m; ++l) {
            if (mp[k][l] != '#') {
              continue;
            } else if (!visited[k][l]) {
              ok = true;
              goto OUT;
            }
          }
        }

        if (!ok) {
          ans = std::min(ans, minimum);
        }
OUT:;
      }
    }

    if (ans == INT_MAX) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0 ^ 0;
}
