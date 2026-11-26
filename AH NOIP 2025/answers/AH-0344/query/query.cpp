#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[50005];
ll n, m;
void solve()
{
    //
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        cout << l * a[l] << '\n';
    }
    //
    cout << '\n';
}
int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}