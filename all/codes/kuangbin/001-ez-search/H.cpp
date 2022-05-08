/* HOW H ? 2022-04-25 13:42:42 */
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

static const char* s[] = {
  "FILL(1)",
  "FILL(2)",
  "DROP(1)",
  "DROP(2)",
  "POUR(1,2)",
  "POUR(2,1)",
};

static const int N = 111;
static int dist[N][N];
std::queue<std::pair<int, int> > q;

std::string ops[N][N], *ptr = (std::string*)(NULL);
void set(int a, int b, char op) {
  if (dist[a][b] != 0) {
    return;
  }
  dist[a][b] = 1;
  q.push(std::pair<int, int>(a, b));
  ops[a][b] = *ptr + op;
}

int main() {

  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);

  q.push(std::pair<int, int>(0, 0));
  dist[0][0] = 1;

  std::string ans;

  while (q.size()) {
    std::pair<int, int> t = q.front();
    q.pop();

    int a = t.first, b = t.second;

    if (a == C || b == C) {
      ans = ops[a][b];
      break;
    }

    ptr = &ops[a][b];

    set(A, b, '1');
    set(a, B, '2');
    set(0, b, '3');
    set(a, 0, '4');
    set(std::max(a - B + b, 0), std::min(B, a + b), '5');
    set(std::min(A, a + b), std::max(b - A + a, 0), '6');
  }

  if (ans.empty()) {
    puts("impossible");
  } else {
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); ++i) {
      puts(s[ans[i] - '1']);
    }
  }

  return 0 ^ 0;
}
