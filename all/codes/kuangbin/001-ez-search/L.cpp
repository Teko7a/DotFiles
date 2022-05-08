/* HOW L ? 2022-04-27 20:40:45 */
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

static const int N = 101;
static int n, m;
static char mp[N][N];
static int p[N * N];
static int size[N * N];

int find(int x) {
  return p[x] = p[x] == x ? p[x] : find(p[x]);
}

static const int dx[] = {0 , 0  , 1  , 1 , 1 , -1 , -1 , -1};
static const int dy[] = {1 , -1 , -1 , 0 , 1 , -1 , 0  , 1};

std::vector<int> ans;

int main() {

  while (scanf("%d%d", &n, &m) && m != 0) {
    int cnt = n * m;
    for (int i = 0; i < n; ++i) {
      scanf(" %[^\n]", mp[i]);
      for (int j = 0; j < m; ++j) {
        p[i * m + j] = i * m + j;
        size[i * m + j] = 1;
        cnt -= mp[i][j] == '*';
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == '@') {
          for (int I = 0; I < 8; ++I) {
            int x = i + dx[I], y = j + dy[I];
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '*') {
              continue;
            } else {
              int px = find(x * m + y), py = find(i * m + j);
              if (px != py) {
                if (size[px] < size[py]) {
                  std::swap(px, py);
                }
                p[py] = px;
                size[px] += size[py];
                cnt -= 1;
              }
            }
          }
        }
      }
    }

    ans.push_back(cnt);
  }

  for (int i = 0; i < (int) ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }

  return 0 ^ 0;
}
