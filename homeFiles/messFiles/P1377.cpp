#include <bits/stdc++.h>

using i64 = long long; // <+>

template <class Fun> struct y_combinator_result {
  Fun fun_;
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int stk[114514];

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);

  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x;
    a[x] = i;
  }

  int top = 0;

  std::vector<int> ls(n + 1), rs(n + 1);

  for (int i = 1; i <= n; ++i) {
    int k = top;
    while (k && a[stk[k]] > a[i])
      k--;
    if (k)
      rs[stk[k]] = i;
    if (k < top)
      ls[i] = stk[k + 1];
    stk[top = ++k] = i;
  }

  y_combinator([&](auto dfs, int x) -> void {
    if (x) {
      std::cout << x << ' ';
      dfs(ls[x]);
      dfs(rs[x]);
    }
  })(stk[1]);

  return 0 ^ 0;
}
