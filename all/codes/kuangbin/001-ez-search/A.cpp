/* HOW A ? 2022-04-25 02:15:38 */
#include <cstdio>

static int n, k, ans;
static const int N = 8;

static char m[N][N];
static bool visited[N];

void dfs(int rmn, int pos) {
  // all chesses ...
  if (!rmn) {
    ans += 1;
    return;
  }
  // to search
  for (int i = pos; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && m[i][j] == '#') {
        visited[j] = true;
        if (i + 1 != n) {
          // check the edge..
          dfs(rmn - 1, i + 1);
        } else if (rmn == 1) {
          // no more possibility
          ans += 1;
        }
        visited[j] = false;
      }
    }
  }
}

int main() {

  while (scanf("%d%d", &n, &k) && (~n && ~k)) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      visited[i] = false;
    }
    for (int i = 0; i < n; ++i) {
      scanf(" %[^\n]", m[i]);
    }
    dfs(k, 0);
    printf("%d\n", ans);
  }

  return 0 ^ 0;
}
