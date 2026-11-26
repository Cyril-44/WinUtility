#include <iostream>
#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

using ll = long long;
constexpr int maxn = 100000;

struct price
{
    int x, y;
} a[maxn + 5];

template <typename tp = int>
tp read()
{
    char ch;
    while ((ch = getchar()) && (ch < '0' || ch > '9'));
    tp ans = ch - '0';
    while ((ch = getchar()) && ch >= '0' && ch <= '9')
        ans = ans * 10 + ch - '0';
    return ans;
}

int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);

    int n = read();
    ll m = read<ll>();

    for (int i = 1; i <= n; i++)
    {
        a[i].x = read();
        a[i].y = read();
    }

    int minv = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++)
        minv = min(minv, a[i].x + a[i].y);
    sort(a + 1, a + n + 1, [](const price& x, const price& y) { return x.x < y.x; });

    ll cur = 0, ans = m / minv * 2;
    for (int i = 1; i <= n; i++)
    {
        cur += a[i].x;
        if (cur > m)
            break;
        ans = max(ans, i + (m - cur) / minv * 2);
    }
    cout << ans << endl;

    return 0;
}