#include <bits/stdc++.h>
using namespace std;

#define filename "sale"
#define multicases

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

template<class T> bool vmax(T &a, T b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, T b) { return b < a ? (a = b, 1) : 0; }

const int N = 5e4+2;

const int P = 998244353;
void vadd(int &a, int b) { a += b; if(a >= P) a -= P; }

int Case;

int f[5002][5002];
int pw[N];

int fac[N], fac_inv[N], inv[N];
int C(int n, int m) {
    if(n < m || n < 0 || m < 0) return 0;
    return 1ll * fac[n] * fac_inv[n-m] % P * fac_inv[m] % P;
}

int n, m;
int a[N];

void WaterM() {
    cin >> n >> m;
    upw(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1, greater<int>());

    int ans = 0;
    int r = 1;
    upw(i, 1, n) {
        while(r <= n && a[r] > a[i] / 2) ++r;
        upw(j, i+1, r-1) {
            if(a[j] == a[i]) continue;
            int p = n;
            upw(k, 0, min(j-i-1, m-2)) {
                while(p >= r && a[p] < a[i] - a[j]) --p;
                vadd(ans, 1ll * C(j-i-1, k) * f[i-1][m-1 - (k+1)] % P * pw[n-p] % P);
                //cerr << i << ' ' << j << ' ' << k << ' ' << p << '\n';
            }
        }
        //cerr << i << ' ' << r << ": " << ans << '\n';
    }
    cout << (pw[n] - ans + P) % P << '\n';
}

signed main() {
#ifdef filename
    freopen(filename".in", "r", stdin), freopen(filename".out", "w", stdout);
#endif

    scanf("%d", &Case);
    signed _ = 1;
#ifdef multicases
    scanf("%d", &_);
#endif // multicases

    f[0][0] = 1;
    upw(i, 1, 5000) {
        upw(j, 1, 5000) {
            vadd(f[i][j], f[i-1][j-1]);
            if(j >= 2) vadd(f[i][j], f[i-1][j-2]);
        }
    }
    fac[0] = fac_inv[0] = 1;
    inv[1] = 1;
    pw[0] = 1;
    upw(i, 2, N-2) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    upw(i, 1, N-2) {
        fac[i] = 1ll * fac[i-1] * i % P;
        pw[i] = 2ll * pw[i-1] % P;
        fac_inv[i] = 1ll * fac_inv[i-1] * inv[i] % P;
    }
/*
    upw(i, 1, 5) {
        upw(j, 1, 5) cerr << f[i][j] << ' ';
        cerr << '\n';
    }
*/
    while(_--) WaterM();
    return 0;
}
/*
MHFGA
*/
