/* HOW F ? 2022-04-25 11:35:59 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cassert>

// 1061
static const int N = 1070;

bool is(int x) {
  if (x < 2) {
    return false;
  }
  for (int i = 2; 1LL * i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

static int top = 0, primes[N];
static bool visited[9010];
static int pow10[4];

int main() {

  for (int i = 0; i < 4; ++i) {
    pow10[i] = !i ? 1 : pow10[i - 1] * 10;
  }

  for (int i = 1001; i < 10000; i += 2) {
    if (is(i)) {
      primes[top ++] = i;
    }
  }

  int tt;
  scanf("%d", &tt);
  while (tt --) {
    int a, b;
    scanf("%d%d", &a, &b);

    memset(visited, 0X00, sizeof visited);

    std::queue<std::pair<int, int> > q;
    q.push(std::pair<int, int>(a, 0));
    visited[a - 1000] = true;

    while (q.size()) {
      std::pair<int, int> t = q.front();
      q.pop();
      
      int x = t.first, d = t.second;

      if (x == b) {
        printf("%d\n", d);
        goto OUT;
      }
    
      int divide[4];
      divide[3] = x / 1000;
      divide[2] = x / 100 % 10;
      divide[1] = x / 10 % 10;
      divide[0] = x % 10;

      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
          if (divide[i] == j) {
            continue;
          }

          int X = x - pow10[i] * (divide[i] - j);
          std::pair<int, int> temp(X, d + 1);

          if (X < 1000 || X >= 10000) {
            continue;
          } else if (visited[X - 1000]) {
            continue;
          } else if (std::binary_search(primes, primes + top, X)) {
            q.push(temp);
            visited[X - 1000] = true;
          }
        }
      }
    }

    puts("Impossible");
OUT:;
  }

  return 0 ^ 0;
}
