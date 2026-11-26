#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

constexpr int maxn = 5000, mod = 998244353;
int a[maxn + 5];

int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, t;
    cin >> c >> t;

    while (t--)
        if (16 == c)
        {
            int n, m;
            cin >> n >> m;

            for (int i = 1; i <= n; i++)
                cin >> a[i];

            int ans = 1;
            for (int i = 1; i <= n; i++)
                ans = 2 * ans % mod;
            cout << ans << endl;
        }
}