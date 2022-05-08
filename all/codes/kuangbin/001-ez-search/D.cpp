/* HOW D ? 2022-04-25 04:39:09 */
#include <cstdio>
#include <cstring>

static const int N = 15 + 1;

static int mp[N][N], t[N][N], ans[N][N];
static int n, m;

static int dx[] = {0, 1, -1, 0, 0};
static int dy[] = {0, 0, 0, 1, -1};

int get(int x, int y) {
  int ans = mp[x][y];
  for (int i = 0; i < 5; ++i) {
    int px = x + dx[i], py = y + dy[i];
    if (px < 0 || px >= n || py < 0 || py >= m) {
      continue;
    }
    ans += t[x + dx[i]][y + dy[i]];
  }
  return ans % 2;
}

int cal() {
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (get(i - 1, j)) {
        t[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    if (get(n - 1, i)) {
      return -1;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += t[i][j];
    }
  }

  return ans;
}

int main() {

  scanf("%d%d", &n, &m);

  int min = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &mp[i][j]);
    }
  }

  for (int i = 0; i < 1 << m; ++i) {
    memset(t, 0X00, sizeof t);
    for (int j = 0; j < m; ++j) {
      t[0][j] = i >> j & 1;
      // t[0][m - 1 - j] = i >> j & 1;
    }

    int num = cal();
    if (num >= 0 && (min < 0 || min > num)) {
      min = num;
      memcpy(ans, t, sizeof t);
    }
  }

  if (~min) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", ans[i][j], " \n"[j == m - 1]);
      }
    }
  } else {
    puts("IMPOSSIBLE");
  }

  return 0 ^ 0;
}
