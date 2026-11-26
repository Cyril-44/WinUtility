#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Read() {
    ll x = 0; int sig = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 365, inf = 1e9;
int n, m, fa[N], siz[N], f[N][N][N], g[N][N];
vector<int> e[N];
void Solve() {
    int i, j, p, q; n = Read(), m = Read();
    for(i = 2; i <= n; i++) fa[i] = Read();
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= n; j++) for(p = 0; p <= n; p++) f[i][j][p] = -inf;
        f[i][1][0] = f[i][0][1] = 0, siz[i] = 1;
    }
    for(i = n; i; i--) {
        for(p = 0; p <= siz[i]; p++) for(q = n; q >= 0; q--) {
            if(q) f[i][p + 1][q - 1] = max(f[i][p + 1][q - 1], f[i][p][q]);
            f[i][p][q] += p;
        } 
        if(i > 1) {
            for(p = 0; p <= n; p++) for(q = 0; q <= n; q++) g[p][q] = -inf;
            for(p = 0; p <= siz[fa[i]]; p++) for(q = 0; q <= siz[i]; q++) {
                int pmax = 0, qmax = 0;
                for(j = 0; j <= n; j++) {
                    pmax = max(pmax, f[fa[i]][j][p]), qmax = max(qmax, f[i][j][q]);
                    g[j][p + q] = max(g[j][p + q], max(pmax + f[i][j][q], qmax + f[fa[i]][j][p]));
                }
            }
            memcpy(f[fa[i]], g, sizeof(g)), siz[fa[i]] += siz[i];
        }
    }
    int ans = 0;
    for(i = 0; i <= n; i++) for(j = 0; j <= n; j++) ans = max(ans, f[1][i][j]);
    Write(ans), putchar('\n');
    for(i = 1; i <= n; i++) e[i].clear(), siz[i] = 0;
}
int main() {
    freopen("tree.in", "r", stdin), freopen("tree.out", "w", stdout);
    int T = Read();
    while(T--) Solve();
}