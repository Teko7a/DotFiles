/* HOW B ? 2022-04-25 03:33:47 */
#include <cstdio>
#include <queue>

struct tuple {
  int x, y, z, d;
  tuple(int _x, int _y, int _z, int _d) {
    x = _x;
    y = _y;
    z = _z;
    d = _d;
  }
  tuple() {
    x = y = z = d = 0;
  }
  bool operator== (const tuple &_) const {
    return x == _.x && y == _.y && z == _.z;
  }
};

std::queue<tuple> q;
tuple S, E;

static int l, r, c;
static const int N = 31;
static char m[N][N][N];
static bool visited[N][N][N];

static const int dx[] = {1, -1, 0, 0, 0, 0};
static const int dy[] = {0, 0, 1, -1, 0, 0};
static const int dz[] = {0, 0, 0, 0, 1, -1};

int main() {

  while (scanf("%d%d%d", &l, &r, &c) && (l && r && c)) {
    q = std::queue<tuple>();
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < r; ++j) {
        scanf(" %[^\n]", m[i][j]);
        // printf("???");puts(m[i][j]);
        for (int k = 0; k < c; ++k) {
          if (m[i][j][k] == 'S') {
            S = tuple(i, j, k, 0);
            visited[i][j][k] = true;
            q.push(S);
          } else {
            visited[i][j][k] = false;
            if (m[i][j][k] == 'E') {
              E = tuple(i, j, k, 000);
            }
          }
        }
      }
    }

    while (q.size()) {
      tuple t = q.front();
      if (t == E) {
        printf("Escaped in %d minute(s).\n", t.d);
        goto OUT;
      }

      q.pop();

      int x = t.x, y = t.y, z = t.z, d = t.d;

      for (int i = 0; i < 6; ++i) {
        int px = x + dx[i];
        int py = y + dy[i];
        int pz = z + dz[i];
        if (px < 0 || px >= l || py < 0 || py >= r || pz < 0 || pz >= c) {
          continue;
        } else if (m[px][py][pz] == '#' || visited[px][py][pz]) {
          continue;
        }

        q.push(tuple(px, py, pz, d + 1));
        visited[px][py][pz] = true;
      }
    }

    puts("Trapped!");

OUT:;
  }
  return 0 ^ 0;
}
