//exam: candy
#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
#define OI "candy"
using namespace std;
struct node {
    int x, y;
    bool operator < (const node &nxt) const {
        return x < nxt.x;
    }
};
const int MAXN = 1e5+5;
node a[MAXN];
int p[MAXN], f[MAXN];
int n, m, x;
int res;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> n >> m; x = m + 1;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        p[i] = a[i].x + a[i].y;
        x = min(p[i], x);
    }

    sort(a + 1, a + 1 + n);
    res = m / x * 2;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].x;
        res = max(res, i + (m - f[i]) / x * 2);
    }

    cout << res;
    return 0;
}
