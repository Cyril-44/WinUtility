#include<bits/stdc++.h>
using namespace std;
int n, m;
int c, t;
int a[100005], ans = 1;
long long MAXN = 998244353;
int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >> t;
    for (int o = 1;o <= t;o++)
    {
        cin >> n >> m;
        for (int i = 1;i <= n;i++) cin >> a[i];
        for (int i = 1;i <= n;i++)
        {
            ans *= 2;
            ans = ans % MAXN;
        }
        cout << ans % MAXN;
    }
    return 0;
}
