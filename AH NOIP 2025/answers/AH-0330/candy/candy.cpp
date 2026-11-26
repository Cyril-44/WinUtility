#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + '0');
    else write(x / 10), putchar(x % 10 + '0');
}
void write(int x, char c) { write(x); putchar(c); }
const int N = 1e5 + 55;
int n, m, x[N], y[N];
signed main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    n = read(), m = read();
    int mn = 1e18;
    for (int i = 1;i <= n;i++) {
        x[i] = read(), y[i] = read();
        mn = min(mn, x[i] + y[i]);
    }
    sort(x + 1, x + 1 + n);
    int sum = 0, ans = 0;
    for (int i = 0;i <= n;i++) {
        sum += x[i];
        if (sum <= m) ans = max(ans, i + (m - sum) / mn * 2);
    }
    write(ans);
    return 0;
}
