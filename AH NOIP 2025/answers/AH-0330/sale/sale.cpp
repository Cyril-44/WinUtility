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
const int MOD = 998244353;
const int N = 5e4 + 33;
int Pow(int o, int b) {
    int r = 1, x = o, p = b;
    while (p) {
        if (p & 1) r = r * x % MOD;
        p >>= 1, x = x * x % MOD;
    }
    return r;
}
int n, c, t, m, a[N], b[N], dp[N];
struct node { int id, aa, bb, ww; } d[N];
bool cmp(node n1, node n2) {
    if (n1.bb != n2.bb) return n1.bb > n2.bb;
    if (n1.aa != n2.aa) return n1.aa > n2.aa;
    return n1.id < n2.id;
}
signed main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    c = read(), t = read();
    while (t--) {
        n = read(), m = read();
        bool chkA = 1;
        for (int i = 1;i <= n;i++) a[i] = read(), a[i] *= 2, chkA &= (a[i] == a[1]);
        if (m == 2 * n - 1 || chkA) { write(Pow(2, n), '\n'); continue; }
        int top = (1 << n), cnt = 0;
        for (int o = 0;o < top;o++) {
            vector<int> vec;
            int tmp = o;
            for (int i = 1;i <= n;i++)
                vec.push_back(tmp % 2), tmp >>= 1;
            for (int i = 0;i < n;i++) {
                if (vec[i]) b[i + 1] = a[i + 1] / 2;
                else b[i + 1] = a[i + 1];
                d[i + 1] = {i + 1, a[i + 1], b[i + 1], vec[i] + 1};
            }
            memset(dp, 0, sizeof(dp));
            for (int i = 1;i <= n;i++)
                for (int j = m;j >= vec[i - 1] + 1;j--)
                    dp[j] = max(dp[j], dp[j - vec[i - 1] - 1] + a[i]);
            int s1 = dp[m], s2 = 0, mo = m;
            sort(d + 1, d + 1 + n, cmp);
            for (int i = 1;i <= n;i++)
                if (mo >= d[i].ww) s2 += d[i].aa, mo -= d[i].ww;
            if (s1 == s2) cnt++;
        }
        write(cnt % MOD, '\n');
    }
    return 0;
}
