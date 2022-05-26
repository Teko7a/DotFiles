#include <bits/stdc++.h>

using i64 = long long; // <+>

template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

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

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <class T> T randint(T a, T b) {
  return std::uniform_int_distribution<T>(a, b)(rng);
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);

  for (auto &i : a)
    std::cin >> i;
  for (auto &i : b)
    std::cin >> i;

  if (a[0] != b[0]) {
    return std::cout << "NO\n", void();
  }

  std::array<int, 2> vis{};

  for (int i = 0; i < n; ++i) {
    if ((b[i] < a[i] && !vis[0]) || (b[i] > a[i] && !vis[1])) {
      return std::cout << "NO\n", void();
    }
    vis[0] |= a[i] == -1;
    vis[1] |= a[i] == +1;
  }

  std::cout << "YES\n";
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
