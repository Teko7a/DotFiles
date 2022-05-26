#include <bits/stdc++.h>

using i64 = long long; // <+>

template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto a = multivector<int>(n, m, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }

  int x = 0;
  while (x < n && std::is_sorted(a[x].begin(), a[x].end())) {
    x += 1;
  }

  if (x == n) {
    return std::cout << "1 1\n", void();
  }

  auto b = a[x];
  std::sort(b.begin(), b.end());

  std::vector<int> p;
  for (int j = 0; j < m; ++j) {
    if (a[x][j] != b[j]) {
      p.push_back(j);
    }
  }

  if ((int)p.size() > 2) {
    return std::cout << "-1\n", void();
  }

  for (int i = 0; i < n; ++i) {
    std::swap(a[i][p[0]], a[i][p[1]]);
    if (!std::is_sorted(a[i].begin(), a[i].end())) {
      return std::cout << "-1\n", void();
    }
  }

  for (int i = 0; i < 2; ++i) {
    std::cout << p[i] + 1 << " \n"[i];
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
