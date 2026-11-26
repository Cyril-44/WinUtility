#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n;
ll m, ans;

struct node
{
    int x, y;
} a[N];

int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int minn = 0x7fffffff, id, lst;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        ll sum = a[i].x + a[i].y;
        if (sum < minn)
        {
            minn = sum;
            id = i;
        }
    }
    sort(a + 1, a + n + 1, [](const node& x, const node& y){ return x.x < y.x; });
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].x > minn / 2 || m < a[i].x)
        {
            lst = i - 1;
            break;
        }
        if (i != id)
        {
            m -= a[i].x;
            ++ans;
        }
    }
    ans += m / minn * 2;
    m -= m / minn * minn;
    for (int i = lst; i > 0; --i)
    {
        if (m + a[i].x >= minn)
        {
            m -= minn - a[i].x;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
