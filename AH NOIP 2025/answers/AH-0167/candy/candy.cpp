#include <bits/stdc++.h>
using namespace std;
int n, a[100005][3];
long long m, ans;
int b[100005];
int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    long long minn = 1, maxx = 0;
    int t = 1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i][1] >> a[i][2];
        a[i][0] = a[i][1] + a[i][2];
        if (a[i][0] < a[minn][0])
            minn = i;
            maxx = max(a[minn][1], a[minn][2]);
        if (a[i][1] < a[i][2])
        {
            b[t] = a[i][1];
            t++;
        }
    }
    sort(b + 1, b + t + 1);
    for (int i = 1;i <= t - 1;i++)
    {
        if (b[i] < maxx and m - b[i] >= 0)
        {
            ans++;
            m -= b[i];
        }
        else break;
    }
    if (m == 0) cout << ans;
    else
    {
        ans += (m/a[minn][0]) * 2;
        m /= a[minn][0];
        if (a[minn][1] > a[minn][2])
        {
            if (m > a[minn][1])ans++;
        }
        else
        {
            if (m > a[minn][2])ans++;
        }
        cout << ans;
    }
    return 0;
}
