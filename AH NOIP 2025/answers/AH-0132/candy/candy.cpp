#include <bits/stdc++.h>
#define int long long
#define loop(i, x, n) for(int i = x; i <= n; i++)
#define loo(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long double INF = 1000000005;
int min_element_v(vector<int> v)
{
    int ans = INF;
    loo (i, 0, v.size())
        ans = min(ans, v[i]);
    return ans;
}
signed main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, m, sum = 0;
    cin >> n >> m;
    vector<long double> x(n, INF), y(n, INF), X;
    loo (i, 0, n)
    {
        cin >> x[i] >> y[i];
        X.push_back((x[i] + y[i]) / 2.0);
    }
    loo (i, 0, n)
    {
        x.push_back(X[i]); y.push_back(X[i]);
        // if i >= n, then they're bundled
    }
    long double wmin;
    vector<bool> fx(2 * n, 1), fy(2 * n + 5, 0); // 0 stand for unavailable
    while (m > 0)
    {
        // init
        /*loo (i, 0, x.size() - 1)
            if (x[i] > m && fx[i]) {x[i].erase(); fx[i].erase(); y[i].erase(); fy[i].erase();}
        loo (i, 0, y.size() - 1)
            if (y[i] > m && fy[i]) {x[i].erase(); fx[i].erase(); y[i].erase(); fy[i].erase();}*/

        // wmin
        long double xmin = INF, ymin = INF, xmini, ymini;
        long double xnext = INF, ynext = INF;
        loo (i, 0, x.size())
        {
            if (!fx[i]) continue;
            //xmin = min(xmin, x[i]);
            if (i >= n)
            {
                if (m < x[i] * 2.0) continue;
            }
            if (x[i] < xmin)
            {
                long double xnextnow = ((i < n) ? y[i] : x[i]);
                xmin = x[i];
                xmini = i;
                xnext = xnextnow;
            }
            else if (x[i] == xmin)
            {
                long double xnextnow = ((i < n) ? y[i] : x[i]);
                if (xnext > xnextnow)
                {
                    xmini = i;
                    xnext = xnextnow;
                }
            }
        }
        loo (i, 0, y.size())
        {
            if (!fy[i]) continue;
            if (i >= n)
            {
                if (m < y[i] * 2.0) continue;
            }
            if (y[i] < ymin)
            {
                long double ynextnow = ((i < n) ? x[i] : y[i]);
                ymin = y[i];
                ymini = i;
                ynext = ynextnow;
            }
            else if (y[i] == ymin)
            {
                long double ynextnow = ((i < n) ? x[i] : y[i]);
                if (ynext > ynextnow)
                {
                    ymini = i;
                    ynext = ynextnow;
                }
            }
        }

        wmin = min(xmin, ymin);
        if (m < wmin) break; // border
        short f0 = -1; // -1 stand for bund, 0 stand for x, 1 stand for y
        if (wmin == xmin && wmin == ymin)
        {
            if (xnext <= ynext)
            {
                if (xmini < n)
                    f0 = 0;
                else
                    f0 = -1;
            }
            else
            {
                if (ymini < n)
                    f0 = 1;
                else
                    f0 = -1;
            }
        }
        else if (wmin == xmin && wmin != ymin) // xmin < ymin, choose x
        {
            if (xmini < n) f0 = 0;
            else f0 = -1;
        }
        else // y
        {
            if (ymini < n) f0 = 1;
            else f0 = -1;
        }

        // work
        if (f0 == 0)
        {
            m -= wmin;
            sum++;
            fx[xmini] = 0; fy[xmini] = 1;
        }
        else if (f0 == 1)
        {
            m -= wmin;
            sum++;
            fy[ymini] = 0; fx[ymini] = 1;
        }
        else if (f0 == -1)
        {
            m -= 2.0 * wmin;
            sum += 2;
        }
    }
    cout << sum;
    return 0;
}
