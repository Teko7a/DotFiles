/* HOW C ? 2022-04-25 04:15:54 */
#include <cstdio>
#include <queue>
#include <utility>
#include <cassert>

static const int N = 1E5 + 7;
static bool visited[N];

int main() {
  int n, k;

  scanf("%d%d", &n, &k);

  if (n >= k) {
    printf("%d\n", n - k);
    return 0 - 0;
  }

  std::queue<std::pair<int, int> > q;

  q.push(std::pair<int, int>(n, 0));
  visited[n] = true;

  while (q.size()) {
    std::pair<int, int> t = q.front();
    int x = t.first, d = t.second;
    q.pop();

    for (int i = 0; i < 3; ++i) {
      int t = !i ? x + 1 : i == 1 ? x - 1 : x * 2;
      if (t < 0 || t > N - 7) {
        continue;
      } else if (visited[t]) {
        continue;
      } else {
        q.push(std::pair<int, int>(t, d + 1));
        visited[t] = true;

        if (k == t) {
          printf("%d\n", d + 1);
          return 0 - 0;
        }
      }
    }
  }

  // __builtin_unreachable();
  assert(false);

  return 0 ^ 0;
}
