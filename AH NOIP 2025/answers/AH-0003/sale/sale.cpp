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
const int N = 5005;
const ll Mod = 998244353;
int n, m, a[N];
ll pw[N], f[N][N];
void Add(ll &x, ll y) { x += y; if(x >= Mod) x -= Mod; }
void Init(int n) {
    int i, j; pw[0] = 1;
    for(i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2ll % Mod;
    for(i = 0; i <= n; i++) {
        f[i][0] = 1;
        for(j = 1; j <= i; j++) f[i][j] = f[i - 1][j], Add(f[i][j], f[i - 1][j - 1]);
    }
}
ll C(int x, int y) { if(x < y || y < 0) return 0; return f[x][y]; }
void Solve() {
    int i, j = 0, p, q; ll ans = 0; n = Read(), m = Read();
    for(i = 1; i <= n; i++) a[i] = Read();
    sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
    for(i = 1; i <= n; i++) {
        while(j < n && a[j + 1] / 2 >= a[i]) j++;
        q = n;
        for(p = i - 1; p > j; p--) if(a[p] != a[i]) {
            while(q && a[i] + a[q] < a[p]) q--;
            int q_ = max(i, q);
            Add(ans, pw[n - q_] * C(i - 2, m - p - 1) % Mod);
        }
    }
    Write((pw[n] - ans + Mod) % Mod), putchar('\n');
}
int main() {
    freopen("sale.in", "r", stdin), freopen("sale.out", "w", stdout);
    int T = Read(); T = Read(), Init(N - 5);
    while(T--) Solve();
}