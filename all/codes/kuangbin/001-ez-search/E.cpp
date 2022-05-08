/* HOW E ? 2022-04-25 10:00:41 */
#include <cstdio>
#include <cstring>
#include <queue>

// using i64 = long long;
typedef long long i64;

i64 n;

bool dfs(int x, i64 num) {
  if (num % n == 0) {
    printf("%lld\n", num);
    return true;
  }

  if (x == 19) {
    return false;
  }

  if (dfs(x + 1, num * 10)) {
    return true;
  }

  if (dfs(x + 1, num * 10 + 1)) {
    return true;
  }

  return false;
}

int main() {

  while (scanf("%lld", &n) && n) {
    dfs(1, 1);
  }

  return 0 ^ 0;
}
