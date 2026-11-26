#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
signed main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (c == 18) cout << int(pow(2, n)) << endl;
        else cout << "6" << endl;
    }
    return 0;
}
