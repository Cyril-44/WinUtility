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
const int N = 8e3 + 33;
int T, n, m, p[N], x[N], c[N][N], ans;
vector<int> kids[N];
void Tdfs(int u) {
    memset(c[u], 0, sizeof(c[u]));
    for (auto v : kids[u]) {
        Tdfs(v);
        for (int i = 0;i < n;i++)
            c[u][i] += c[v][i];
    }
    c[u][x[u]]++;
}
void dfs(int s) {
    if (s == 0) {
        Tdfs(1);
        int sum = 0;
        for (int i = 1;i <= n;i++) {
            int pos = 1e18;
            for (int j = 0;j <= n;j++)
                if (c[i][j] == 0) pos = min(pos, j);
            sum += pos;
        }
        ans = max(ans, sum);
    } else {
        int mxx = 0;
        for (auto y : kids[s]) mxx = max(mxx, x[y]);
        for (int i = mxx;i < n;i++)
            x[s] = i, dfs(s - 1);
    }
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    T = read();
    while (T--) {
        n = read(), m = read();
        for (int i = 1;i <= n;i++) kids[i].clear();
        ans = 0;
        memset(x, 0, sizeof(x));
        for (int i = 2;i <= n;i++)
            p[i] = read(), kids[p[i]].push_back(i);
        dfs(n);
        write(ans, '\n');
    }
    return 0;
}
