/* HOW M ? 2022-04-27 22:09:11 */
#include <bits/stdc++.h>
using namespace std;

using node = tuple<int, int, int>;
using vi = vector<int>;

int main() {
  vector<int> s(3);
  auto pull = [&](int i, int j, vi &t3) -> vi { //�� i ���� j ��
    int w = min(t3[i], s[j] - t3[j]);
    t3[i] -= w, t3[j] += w;
    return t3;
  };

  while (cin >> s[0] >> s[1] >> s[2] and s[0]) {
    if (s[1] < s[2]) {
      swap(s[1], s[2]);
    }

    //һ����s[1] >= s[2], ������s[0] = s[1] && s[2] == 0ʱ���ǺϷ���
    bitset<101> v[101][101];

    //��¼�Ƿ������������¼ֵ���ֲ�bfs�ڼ��������Ǽ���

    queue<vi> sk, wbw;
    queue<vi> &q = sk, &q2 = wbw;
    q.push({s[0], 0, 0});
    for (int ans = 1; q.size(); ans++) { //�ֲ�bfs
      for (; q.size(); q.pop()) {
        auto pos = q.front();
        for (int i = 0; i < 9; i++) {
          if (i / 3 != i % 3) {
            auto np = pull(i / 3, i % 3, pos);
            if (!v[np[0]][np[1]][np[2]]) {
              q2.push(np), v[np[0]][np[1]][np[2]] = 1;
            }
          }
        }
      }
      swap(q, q2); //����ָ��
      if (v[s[0] / 2][s[0] / 2][0]) {
        cout << ans << endl;
        break;
      }
    }
    if (!v[s[0] / 2][s[0] / 2][0]) {
      cout << "NO\n";
    }
  }

  return 0;
}

