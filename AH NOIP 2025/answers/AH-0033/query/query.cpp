#include <iostream>
#include <limits>

using namespace std;

using ll = long long;
using ull = unsigned long long;
constexpr int maxn = 50000;
int a[maxn + 5];

namespace subtask1
{
    constexpr int maxn = 3000, maxk = 11;
    ll s[maxn + 5], st[maxn + 5][maxk + 5];
    int p[maxn + 5];

    ll query(int l, int r)
    {
        int k = p[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
    
    void solve(int n, int q)
    {
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i];
        for (int i = 1; i <= n; i++)
            st[i][0] = s[i];
        for (int k = 1; k <= maxk; k++)
            for (int i = 1; i + (1 << k) - 1 <= n; i++)
                st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        for (int i = 2; i <= n; i++)
            p[i] = p[i >> 1] + 1;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            ull ans = 0;
            for (int i = 1; i <= n; i++)
            {
                ll cur = numeric_limits<ll>::min();
                for (int j = i; j >= 1 && i - j + 1 <= r; j--)
                    if (j + l - 1 <= n)
                        cur = max(cur, query(max(i, j + l - 1), min(n, j + r - 1)) - s[j - 1]);
                ans ^= 1ull * i * cur;
            }
            cout << ans << endl;
        }
    }
}

namespace subtask2
{
    constexpr int maxl = 32;
    ll s[maxn + 5], st[maxn + 5][maxl + 5][6];
    int p[maxl + 5];

    inline ll query(int i, int l, int r)
    {
        int k = p[r - l + 1];
        return max(st[i][l][k], st[i][r - (1 << k) + 1][k]);
    }

    void solve(int n, int q)
    {
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i];
        for (int i = 1; i <= n; i++)
            for (int j = i; j >= 1 && i - j + 1 <= maxl; j--)
                for (int k = i; k <= n && k - j + 1 <= maxl; k++)
                    st[i][k - j + 1][0] = s[k] - s[j - 1];
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= 5; k++)
                for (int j = 1; j + (1 << k) - 1 <= maxl; j++)
                    st[i][j][k] = max(st[i][j][k - 1], st[i][j + (1 << (k - 1))][k - 1]);
        for (int i = 2; i <= maxl; i++)
            p[i] = p[i >> 1] + 1;

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            
            ull ans = 0;
            for (int i = 1; i <= n; i++)
                ans ^= 1ull * i * query(i, l, r);
            cout << ans << endl;
        }
    }
}

int main()
{
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    if (n <= 3000)
        subtask1::solve(n, q);
    else
        subtask2::solve(n, q);

    return 0;
}