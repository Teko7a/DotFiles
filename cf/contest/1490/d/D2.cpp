#include <bits/stdc++.h>

using i64 = long long; // <+>

template <class T, class Cmp>
auto cartesian_tree(const std::vector<T> &t,
                    const Cmp &&cmp = std::less<int>()) {
  int n = (int)t.size();
  std::vector<int> p(n, -1), stk;

  for (int i = 0; i < n; ++i) {
    int erased = -1;
    while (stk.size() && cmp(t[i], t[stk.back()])) {
      erased = stk.back();
      stk.pop_back();
    }

    p[i] = stk.size() ? stk.back() : -1;
    if (erased >= 0) {
      p[erased] = i;
    }

    stk.push_back(i);
  }

  return p;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }

  auto p = cartesian_tree(a, std::greater<int>());

  std::vector<int> dep(n, -1);

  for (int i = 0; i < n; ++i) {
    int loc = i;
    while (loc >= 0) {
      dep[i] += 1;
      loc = p[loc];
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << dep[i] << " \n"[i + 1 == n];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt--) {
    solve();
  }

  return 0 ^ 0;
}
