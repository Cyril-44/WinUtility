#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll x, y;
} c[5005];
ll a[5005], b[5005];
ll dp[5005][5005];
ll n, m, ans, maxn;
ll fun()
{
    for (int i = 1; i <= n; i++)
    {
        c[i].x = a[i];
        c[i].y = b[i];
    }
    sort(c + 1, c + n + 1, [](node a, node b)
    {
        ll t1 = a.x, t2 = b.x;
        if (a.y != b.y) {if (a.y == 1) t1 <<= 1; else t2 <<= 1;}
        if (t1 != t2) return t1 > t2;
        return a.x >= b.x;
    });
    ll sumf = m, s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sumf < c[i].y) continue ;
        sumf -= c[i].y;
        s += c[i].x;
    }
    ll maxx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = b[i]; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
        }
    }
    for (int j = 0; j <= m; j++) maxx = max(maxx, dp[n][j]);
    return s == maxx;
}
void solve()
{
    ans = 0;
    //
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < (1ll << n); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i >> (j - 1)) & 1) b[j] = 2;
            else b[j] = 1;
        }
        ans += fun();
    }
    cout << ans;
    //
    cout << '\n';
}
int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    cin >> T;
    cin >> T;
    while (T--) solve();
    return 0;
}