//exam: sale
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define OI "sale"
using namespace std;
const int MAXN = 5005, P = 998244353;
int qpow(int, int);
bool cmp(int, int);
int a[MAXN], w[MAXN], id[MAXN];
int c, t, n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> c >> t;
    while(t--) {
        cin >> n >> m;

        bool flagA = true; // for case A;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i > 1 && a[i] != a[i - 1]) {
                flagA = false;
            }
        }
        if(flagA) {
            cout << qpow(2, n) << endl;
            continue;
        }

        int cnt = 0;

        for(int S = 0; S < (1 << n); S++) {
            for(int i = 1; i <= n; i++) {
                w[i] = ((S >> (i - 1)) & 1) + 1;
                id[i] = i;
            }

            sort(id + 1, id + 1 + n, cmp);

            int val = 0, rest = m;
            for(int i = 1; i <= n; i++) {
                if(rest >= w[id[i]]) {
                    rest -= w[id[i]];
                    val += a[id[i]];
                }
            }

            vector<int> f(m + 1);
            int maxn = 0;
            for(int i = 1, flag = true; i <= n && flag; i++) {
                for(int j = m; j >= w[i]; j--) {
                    f[j] = max(f[j], f[j - w[i]] + a[i]);
                    maxn = max(maxn, f[j]);
                    if(maxn > val) {
                        flag = false;
                        break;
                    }
                }
            }

            if(val == maxn) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
int qpow(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) {
            res = res * x % P;
        }
        x = x * x % P;
        y >>= 1;
    }
    return res;
}
bool cmp(int x, int y) {
    if(a[x] * w[y] != a[y] * w[x]) {
        return a[x] * w[y] > a[y] * w[x];
    } else if(a[x] != a[y]) {
        return a[x] > a[y];
    } else {
        return x < y;
    }
}
