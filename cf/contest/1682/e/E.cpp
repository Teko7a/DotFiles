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

template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> p(n);
  for (auto &i : p) {
    std::cin >> i;
    --i;
  }

  auto g = multivector<int>(n, 0, 0);
  std::map<std::pair<int, int>, int> id;

  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    id[{u, v}] = id[{v, u}] = i + 1;
  }

  std::vector<int> ord(n, -1);

  for (int i = 0; i < n; ++i) {
    if (~ord[i]) {
      continue;
    }
    std::vector<int> a;

    int k = 0;
    for (int y = i; ord[y] == -1; y = p[y]) {
      ord[y] = k++;
      a.push_back(y);
    }
#define MOD(X) (X + k) % k
    for (auto &x : a) {
      std::sort(g[x].begin(), g[x].end(), [&](int i, int j) {
        return MOD(ord[i] - ord[x]) < MOD(ord[j] - ord[x]);
      });
    }
  }

  std::vector<int> cur(n);

  auto check = y_combinator([&](auto check, int x) -> void {
    if (cur[x] == (int)g[x].size()) {
      return;
    }
    int y = g[x][cur[x]];
    if (g[y][cur[y]] != x) {
      return;
    }
    std::cout << id[{x, y}] << " ";
    cur[x] += 1, cur[y] += 1;
    check(x), check(y);
  });

  for (int i = 0; i < n; ++i) {
    check(i);
  }

  return 0 ^ 0;
}
