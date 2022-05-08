# A. Who is The 19th ZUCCPC Champion
## 题意

输出任一仅含有字母、数字、空格的字符串。

# B. Jiubei and Overwatch
## 题意

打怪兽，玩家可发动一次技能，对全体怪兽造成一次伤害。

设当前时间为 $T$，如果 $T \le K$，伤害为 $T\times X$; 反之则为 $KX + TY - KY$。

问最早在何时消灭所有怪兽？

## 制约

$X, Y, K \in [1, 100]$

$a_i \in [1, 10^9]$

## 解答

二分，选择最大血量操作即可。

## 核心代码

```cpp
int M = *std::max_element(a.begin(), a.end());

i64 basic = 1LL * k * (x - y);

int l = 0, r = 2E9;

while (l < r) {
  i64 mid = (l + r) / 2;
  i64 damage = mid <= k ? mid * x : mid * y + basic;
  if (damage >= M) {
    r = mid;
  } else {
    l = mid + 1;
  }
}

std::cout << l << '\n';
```

# C. Ah, It's Yesterday Once More

> 注：这是在玩南京区域赛的梗

## 题意

给出两种排序算法，构造一个排列，使得其中的 `swap` 操作次数相同。

![两种排序方法](https://espresso.codeforces.com/54b2ac6855db7ad6d08fc158f91f37023d9bd381.png)
## 制约

$n \in [1, 2 \times 10^5]$

## 解答

第二种算法为 **冒泡排序**，因而交换数量为 **逆序对** 个数。

而对于第一种算法，每轮循环开始前 $a_{[1 \sim i - 1]}$ 已然有序且 $a_{i - 1} = n$，此轮之后必有 $a_i$ 归位。

构造递减排列即可。

# E. Disjoint Path On Tree
## 题意

给定一棵 $N$ 个节点的树，求解二元组 $(u, v)$ 的个数，其中 $u, v$ 是俩不相交的简单路径。

路径 $(i, j)$ 与 $(j, i), \,i \ne j$ 视作同一路径。

## 制约

$N \in [1, 2 \times 10 ^ 5]$

## 解答

显然，树上的路径均为简单路径,。容易知道 $N$ 个节点的树的简单路径条数为：

$$
F(N) = N + \displaystyle{\binom{n}{2}} = \dfrac{N \times (N + 1)}{2}
$$

而 $(i, j)$ 与 $(j, i), \,i \ne j$ 视作一样的也没关系，求出所有二元组后除以二即可。

另一方面，所求也等价于 $\Big((F(N) ^ 2 -$ 相交组数 $\Big)$，设两条路径交于 $u$，即选择 

$$
((u, x)_{cyc}, (u, y)_{cyc})_{cyc}
$$

讨论 $x, y$ 的来源：

1. $x \in    u$，即 $\mathrm{cnt}_1 = F(u) - \displaystyle \sum_{to \;\in\;u} F(to)$。
2. $x \notin u$，即 $\mathrm{cnt}_2 = \mathrm{size}_u \times (n - \mathrm{size}_u)$。

注意不能是两点均来自 $x \notin u$。组合起来：

$$
(\mathrm{cnt}_1 + \mathrm{cnt}_2) ^ 2 - (\mathrm{cnt}_2)^2
$$

# 参考代码

<style>
  .rated-user {
    font-family: helvetica neue, Helvetica, Arial, sans-serif;
  text-decoration: none !important;
  font-weight: 700;
  display: inline-block;
}

.user-legendary {
  color: red !important;
}

.user-legendary::first-letter {
  color: #000 !important;
}
</style>

> 注：其中 `Z` 为 [<font class="rated-user user-legendary">jiangly</font>](https://codeforces.com/profile/jiangly) 的整数模板类。


```cpp
Z f(int n) { return 1LL * n * (n + 1) / 2; }

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> G(n);

  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    -- u, -- v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  Z ans = f(n) * f(n);
  std::vector<int> size(n);

  std::function<void(int, int)> dfs = [&](int u, int p) {
    size[u] = 1;
    for (auto &&to : G[u]) if (to != p) {
      dfs(to, u);
      size[u] += size[to];
    }

    Z cnt1 = f(size[u]);
    Z cnt2 = 1LL * size[u] * (n - size[u]);

    for (auto &&to : G[u]) if (to != p) {
      cnt1 -= f(size[to]);
    }

    ans -= (cnt1 + cnt2) * (cnt1 + cnt2) - cnt2 * cnt2;
  };

  dfs(0, -1);

  std::cout << ans / 2 << '\n';
}
```

## 后寄

注：官方题解：

![alt](https://uploadfiles.nowcoder.com/images/20220414/204702037_1649937068938/D2B5CA33BD970F64A6301FA75AE2EB22)
> LCA 是什么东西，不懂，长大了再学。

# F. Sum of Numerators
## 题意

给定 $N, K$，求解将序列 $\{\dfrac{i}{2^K}\}$ 中元素全部约分后的分子和，其中 $i$ 遍历 $1 \sim N$。

## 制约

$N \in [1, 10^9], K \in [0, 10 ^ 9]$

## 解答

首先注意到 $\gcd(2^K, \mathrm{odd}) = 1$，于是我们先将所有奇数和算入答案，我们知道：

$$
\sum_{i = 1}^N[i \% 2 = 1] \times i = \bigg\lceil\dfrac{N}{2}\bigg\rceil ^2
$$

> 即 $\underbrace{1 + 3 + 5 + 7 + \cdots + N}_{x\;项} = x^2$

接下来考虑偶数与 $2 ^ K$ 约分的过程，对于每一个偶数，都可写作 

$$
X = x2 ^ t,\;\mathtt{where}\;\gcd(2, x) = 1
$$

于是 $2 ^ K$ 将会约分所有 $t \le K$ 的部分，使得其变为一段奇数和，使用上述算式求解即可。

最后再加上没有被约分的偶数和即可，即 

$$
\displaystyle\sum_{i = 1}^N[i \% 2 = 0] \times i = \bigg\lfloor\dfrac{N}{2}\bigg\rfloor \times \bigg(\bigg\lfloor\dfrac{N}{2}\bigg\rfloor + 1\bigg)
$$

> 即 $\underbrace{2 + 4 + 6 + 8 + \cdots + N}_{x\;项} = 2 \times (1 + 2 + 3 + 4 + \cdots + \dfrac{N}{2})$

从宏观上来看，这样就做完了。但是整个过程会产生更多的 $1 \sim n$ 的结构，反复计算即可。

# 参考代码

```cpp
using i64 = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;

  i64 ans = 0;
  for (k += 1; k -- && n; n -= (n + 1) / 2) {
    ans += 1LL * ((n + 1) / 2) * ((n + 1) / 2);
    (!k) && (ans += 1LL * (n / 2) * (n / 2 + 1));
  }

  std::cout << ans << '\n';
}
```


# G. Guaba and Computational Geometry
## 题意

在平面上给定一些矩形, 及其权重。选择两个不交的矩形使其权重和最大。或者回答不可能。

## 制约

$n \in [1, 3 \times 10 ^ 5]$

$a_i, b_i, c_i, d_i \in [-10^9, 10^9]$

$w_i \in [1, 10 ^ 9]$

## 解答

若矩形有交，则其在坐标上的分量也有交。

于是分开考虑两维即可，一方面从前往后枚举一个权值，另一方面选择与其最接近（但不相等）的一个不交矩形的权重（处理出后缀最值）。

## 参考代码

```cpp
struct node {
  int l, r;
  i64 val;
  bool operator< (const node &_) const {
    return this->l < _.l;
  }
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), w(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i];
  }

  i64 ans = -1;
  std::vector<node> val(n + 1);
  std::vector<i64> suffix(n + 2);

  auto sol = [&]() {
    std::sort(val.begin() + 1, val.end());
    suffix.back() = 0;
    for (int i = n; i; --i) {
      suffix[i] = std::max(suffix[i + 1], val[i].val);
    }
    for (int i = 1; i <= n; ++i) {
      node t{val[i].r, 0, 0};
      auto pos = std::upper_bound(val.begin() + 1, val.end(), t);
      if (pos != val.end()) {
        ans = std::max(ans, suffix[pos - val.begin() - 1 + 1] + val[i].val);
      }
    }
  };

  for (int i = 1; i <= n; ++i) {
    val[i] = {a[i], c[i], w[i]};
  }

  sol();

  for (int i = 1; i <= n; ++i) {
    val[i] = {b[i], d[i], w[i]};
  }

  sol();

  std::cout << ans << '\n';
}
```

# I. Array Division
## 题意

给定两个等长数组，分别拆分为 $k$ 段，使得每一段都有:

$$
\sum A \ge \sum B
$$

求出最大的 $k$。

## 制约

$n \in [1, 5000]$

$a_i, b_i \in [1, 10 ^ 9]$

## 解答

首先注意到数据范围很小, 可以稍微大胆一些。

设 $dp_i$ 表示前缀长 $i$ 的、能分出的最多组数。

$$
dp_i \leftarrow \max_{j \lt i}\{dp_j + 1\} \mathrm{\;iff.\;} \sum_j^i A \ge \sum_j^i B
$$

预处理出前缀和即可。

## 参考代码
```cpp
dp[0] = 0;

for (int i = 0; i < n; ++i) {
  if (dp[i] != -1) {
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] - a[i] >= b[j] - b[i]) {
        dp[j] = std::max(dp[j], dp[i] + 1);
      }
    }
  }
}

std::cout << dp.back() << '\n';
```

## 后寄

注：官方题解：

令 $c_i = \sum^i_{j=1} a_j − b_j$，不难发现我们只需要求出从非负的位置开始 且以 $c_n$ 结束的的最长上升子序列的长度，经典算法，复杂度 $\mathcal O(n \log n)$

> 非常高。

# post
