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

struct Node {
  int id, val, p, s[2];
  void init(int _id, int _val, int _p) {
    id = _id, val = _val, p = _p, s[0] = s[1] = 0;
  }
};

template<class Cmp>
int cartesian_build(std::vector<Node> &tree,
    const Cmp &&cmp = std::less<>()) {
  int n = tree.size() - 1;
  for (int i = 1; i <= n; ++i) {
    int k = i - 1;
    while (cmp(tree[i].val, tree[k].val)) {
      k = tree[k].p;
    }
    tree[i].s[0] = tree[k].s[1];
    tree[k].s[1] = i;
    tree[i].p = k;
    tree[tree[i].s[0]].p = i;
  }
  return tree[0].s[1];
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<Node> tree(n + 1);
  tree[0].init(0, INT_MAX, 0);
  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x;
    tree[i].init(i, x, 0);
  }

  int root = cartesian_build(tree, std::greater<>());
  std::vector<int> d(n + 1);

  y_combinator([&](auto dfs, int x) -> void {
    for (int i = 0; i < 2; ++i) {
      if (tree[x].s[i]) {
        d[tree[x].s[i]] = d[x] + 1;
        dfs(tree[x].s[i]);
      }
    }
  })(root);

  for (int i = 1; i <= n; ++i) {
    std::cout << d[i] << " \n"[i == n];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
