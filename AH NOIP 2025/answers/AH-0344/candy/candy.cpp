#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x[100005], y[100005], z[100005];
ll n, m, ans, minn;
void solve()
{
    //
    cin >> n >> m;
    minn = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        y[i] += x[i];
        minn = min(minn, y[i]);
    }
    sort(x + 1, x + n + 1);
    z[0] = m / minn * 2;
    ans = z[0];
    m %= minn;
    for (int i = 1; i <= n; i++)
    {
        z[i] = z[i - 1];
        if (m < x[i])
        {
            ll l = x[i] - m;
            ll tmp = (l + minn - 1) / minn;
            z[i] -= tmp * 2;
            m += tmp * minn;
        }
        z[i]++;
        m -= x[i];
        ans = max(ans, z[i]);
    }
    cout << ans;
    //
    cout << '\n';
}
int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}