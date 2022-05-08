---
title: source-code-test
permalink: /blog/source-code-test/
categories: test
tags: test
toc: true
math: true
date: 2022-05-01 23:52:22
updated: 2022-05-02 00:05:11
excerpt: This is the source code of last test post
---

This is the source code of [last test post](https://algo.teko7a.top/blog/test-md-format/)

````md
---
title: test-md-format
permalink: /blog/test-md-format/
categories: test
tags: test
toc: true
math: true
date: 2022-05-01 22:18:19
updated: 2022-05-02 00:00:34
---

# formula

{% note info %}
This is a test for $\LaTeX$ and other formats.
{% endnote %}

$$
f(x) = x ^ 2
$$

$$
\mathrm{ABCDEabcde1234}\\
\mathit{ABCDEabcde1234}\\
\mathbf{ABCDEabcde1234}\\
\mathsf{ABCDEabcde1234}\\
\mathtt{ABCDEabcde1234}\\
\mathcal{ABCDEFGHIJK}\\
\mathscr{ABCDEFGHIJK}\\
\mathfrak{ABCDEFGHIJK}\\
\mathbb{ABCDEFGHIJK}\\
$$

$$
\large P = \frac{\displaystyle{
\sum_{i=1}^n (x_i- x)
(y_i- y)}}
{\displaystyle{\left[
\sum_{i=1}^n(x_i-x)^2
\sum_{i=1}^n(y_i- y)^2
\right]^{1/2}}}\\
$$

$$
\color{black}{黑色},\color{red}{红色},\color{green}{绿色},\color{brown}{棕色},\color{pink}{粉色}\\
\color{white}{白色},\color{blue}{蓝色},\color{red}{红色},\color{yellow}{黄色},\color{gray}{灰色}\\
\color{orange}{橘色},\color{teal}{靛青},\color{darkgray}{深灰},\color{olive}{橄榄},\color{violet}{紫罗兰}\\
\color{lime}{青柠},\color{lightgray}{淡灰},\color{cyan}{青色},\color{magenta}{品红},\color{purple}{紫色}
,\color{silver}{银色}
$$

> 颜色测试失败

$$
\large \underset{j=1}{\overset{\infty}{\LARGE \mathrm K}}\frac{a_j}{b_j}
=\cfrac{a_1}{b_1
+\cfrac{a_2}{b_2
+\cfrac{a_3}{b_3
+\cfrac{a_4}{b_4
+\ddots}}}}\\
$$

$$
\large
\cfrac{a_{1}}{b_{1}+\cfrac{a_{2}}{b_{2}+\cfrac{a_{3}}{b_{3}+\ddots }}}
={\genfrac{}{}{}{}{a_1}{b_1}}  
{\genfrac{}{}{0pt}{}{}{+}}   
{\genfrac{}{}{}{}{a_2}{b_2}}   
{\genfrac{}{}{0pt}{}{}{+}}   
{\genfrac{}{}{}{}{a_3}{b_3}}   
{\genfrac{}{}{0pt}{}{}{+\dots}}\\
$$

# tags

<p class="note note-primary"> primary     </p>
<p class="note note-secondary"> secondary </p>
<p class="note note-success"> success     </p>
<p class="note note-danger"> danger       </p>
<p class="note note-warning"> warning     </p>
<p class="note note-info"> info           </p>
<p class="note note-light"> light         </p>

```html
<p class="note note-primary"> primary     </p>
<p class="note note-secondary"> secondary </p>
<p class="note note-success"> success     </p>
<p class="note note-danger"> danger       </p>
<p class="note note-warning"> warning     </p>
<p class="note note-info"> info           </p>
<p class="note note-light"> light         </p>
```

# code
```go
package main

import "fmt"

func main() {
    ch := make(chan float64)
    ch <- 1.0e10    // magic number
    x, ok := <- ch
    defer fmt.Println(`exitting now\`)
    go println(len("hello world!"))
    return
}
```

<details>
<summary> C++ —— The best language! </summary>

```cpp
#include <bits/stdc++.h>

using i64 = long long; // <+>

void solve() {
  int n;
  std::cin >> n;
  for (int i = n; i > 0; --i) {
    std::cout << i << " \n"[i == 1];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int tt = 1;
  std::cin >> tt;
  while (tt --) {
    solve();
  }

  return 0 ^ 0;
}
```
</details>
````
