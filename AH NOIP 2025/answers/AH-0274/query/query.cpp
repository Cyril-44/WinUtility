#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4+5;
const ll mod = 2<<64;
int n, q, a[N];
ll query(int L, int R)
{
    return n%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for (int j = 1; j <= q; j++)
    {
        int L, R;
        cin >> L >> R;
        cout << query(L, R);
    }
    return 0;
}
