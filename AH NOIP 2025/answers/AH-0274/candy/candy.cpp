#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
#define ll long long
int n;
bool flagb=1;
ll m, cnt;
struct A
{
    int x, y, s;
}a[N];
bool cmp(A p, A q)
{
    if (p.s == q.s)
    {
        return p.x < q.x;
    }
    else
    {
        return p.s < q.s;
    }
}
bool cmp2(A p, A q)
{
    return p.x < q.x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].s = a[i].x+a[i].y;
        if (flagb && a[i].x>=a[i].y)
        {
            flagb = 1;
        }
        else
        {
            flagb = 0;
        }
    }
    if (n == 1)
    {
        int i = 1;
        while (m > 0)
        {
            cnt++;
            if (i%2 == 1)
            {
                m -= a[1].x;
            }
            else
            {
                m -= a[1].y;
            }
            i++;
        }
        cout << cnt;
        return 0;
    }
    if (n == 2)
    {
        int tp = m;
        sort(a+1, a+n+1, cmp);
        cnt = m/a[1].s*2;
        m %= a[1].s;
        int m1, m2;
        if (a[1].x < a[2].x)
        {
            m1 = a[1].x;
            m2 = a[2].x;
        }
        else
        {
            m1 = a[2].x;
            m2 = a[1].x;
        }
        if (m >= m1)
        {
            m -= m1;
            cnt++;
        }
        if (m >= m2)
        {
            m -= m2;
            cnt++;
        }
        int heng = cnt;
        m = tp;
        cnt = m/(a[1].x+a[2].x)*2;
        m %= a[1].x+a[2].x;
        if (a[1].y < a[2].y)
        {
            m1 = a[1].y;
            m2 = a[2].y;
        }
        else
        {
            m1 = a[2].y;
            m2 = a[1].y;
        }
        if (m >= m1)
        {
            m -= m1;
            cnt++;
        }
        if (m >= m2)
        {
            m -= m2;
            cnt++;
        }
        int zong = cnt;
        cout << max(heng, zong);
        return 0;
    }
    if (flagb)
    {
        sort(a+1, a+n+1, cmp);
        cnt = m/a[1].s*2;
        m %= a[1].s;
        sort(a+1, a+n+1, cmp2);
        int i = 1;
        while (m >= a[i].x)
        {
            m -= a[i].x;
            cnt++;
            i++;
        }
        cout << cnt;
        return 0;
    }
    sort(a+1, a+n+1, cmp);
    cnt = m/a[1].s*2;
    m %= a[1].s;
    sort(a+1, a+n+1, cmp2);
    int i = 1;
    while (m >= a[i].x)
    {
        m -= a[i].x;
        cnt++;
        i++;
    }
    cout << cnt;
    return 0;
}
