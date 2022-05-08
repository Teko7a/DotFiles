/* HOW G ? 2022-05-03 00:47:14 */
#include <bits/stdc++.h>

using i64 = long long; // <+>

static const int N = 200007;

std::pair<int, int> e[N];
int deg[N][2];
int nd[N];
int dp[N];
std::vector<int> v[N];

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    auto &[x, y] = e[i];
    std::cin >> x >> y;
    ++ deg[x][0], ++ deg[y][1];
  }

  for (int i = 1; i <= m; ++i) {
    auto &[x, y] = e[i];
    if (deg[x][0] != 1 and deg[y][1] != 1) {
      v[x].push_back(y);
      ++ nd[y];
    }
  }

  std::queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (!nd[i]) {
      q.push(i);
      dp[i] = 1;
    }
  }

  int ans = -1;

  while (q.size()) {
    int t = q.front();
    q.pop();
    ans = std::max(ans, dp[t]);
    for (auto &&i : v[t]) {
      dp[i] = std::max(dp[i], dp[t] + 1);
      if (-- nd[i] == 0) {
        q.push(i);
      }
    }
  }

  std::cout << ans << '\n';

  return 0 ^ 0;
}

