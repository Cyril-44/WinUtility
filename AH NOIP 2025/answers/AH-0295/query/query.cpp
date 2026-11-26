#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 5;

int n, q, a[N];

signed main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    for (int i = 1, l, r; i <= q; ++i)
    {
        cin >> l >> r;
        unsigned long long ans = 0;
        for (int j = 1; j <= n; ++j)
        {
            ans ^= j * a[j];
        }
        cout << ans << '\n';
    }
    return 0;
}
