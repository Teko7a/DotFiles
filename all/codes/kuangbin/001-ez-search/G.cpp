/* HOW G ? 2022-04-25 12:55:10 */
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

static const int N = 222;
char a[N], b[N], c[N];
std::string A, B, C;

int main() {

  int tt;
  scanf("%d", &tt);

  for (int test = 1; test <= tt; ++test) {
    int n;
    scanf("%d", &n);
    scanf("%s%*c%s%*c%s%*c", a, b, c);
    A = std::string(a, a + n);
    B = std::string(b, b + n);
    C = std::string(c, c + n + n);

    std::string P = A, Q = C;
    P += B;
    std::sort(P.begin(), P.end());
    std::sort(Q.begin(), Q.end());

    printf("%d ", test);
    if (P != Q) {
      puts("-1");
      continue;
    }

    std::set<std::string> S;

    bool found = false;
    int ans = 0;
    while (true) {
      std::string s;
      ans += 1;

      for (int i = 0; i < n; ++i) {
        s += B[i];
        s += A[i];
      }

      if (s == c) {
        found = true;
        break;
      }

      if (S.count(s)) {
        // run into a circle
        break;
      }

      S.insert(s);
      A = s.substr(0, n);
      B = s.substr(n);
      // assert(A.size() == B.size());
    }

    if (found) {
      printf("%d\n", ans);
    } else {
      puts("-1");
    }
  }

  return 0 ^ 0;
}
