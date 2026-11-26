#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 5e4+5;
int c, t, n, m;
struct A
{
    int w, v, id, xjb;
}a[N];
bool cmp(A x, A y)
{
    if (x.xjb == y.xjb)
    {
        if (x.v == y.v)
        {
            return x.id < y.id;
        }
        return x.v > y.v;
    }
    return x.xjb > y.xjb;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].v;
        }
        long long ans = pow(2, n);
        cout << ans%mod << '\n';
    }
    return 0;
}
