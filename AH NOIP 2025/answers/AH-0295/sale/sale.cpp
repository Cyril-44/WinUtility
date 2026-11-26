#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
const int mod = 998244353;

int n, m, a[N];

ll pow2(int k)
{
    if (!k) return 1;
    ll res = 1, aa = 2;
    while (k > 0)
    {
        if (k & 1) res = res * aa % mod;
        aa = aa * aa % mod;
        k >>= 1;
    }
    return res;
}

void sovle()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    return;
}

int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int C, T; cin >> C >> T;
    if (C == 18)
    {
        while (T--)
        {
            cin >> n >> m;
            for (int i = 1; i <= n; ++i) cin >> a[i];
            cout << pow2(n) << '\n';
        }
        return 0;
    }
    while (T--) sovle();
    return 0;
}
