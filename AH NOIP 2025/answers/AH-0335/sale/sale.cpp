#include <iostream>
#include <cstdio>
#define MAXN 5005
using namespace std;
const int MOD = 998244353;
int c, t, n, m;
int a[MAXN];
int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        long long ans = 1;
        for(int i=1; i<=n; i++) {
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
