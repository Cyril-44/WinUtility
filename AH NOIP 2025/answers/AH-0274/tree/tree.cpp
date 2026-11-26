#include <bits/stdc++.h>
using namespace std;
int t, n, m;
const int N = 8005;
vector<int> e[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        e.clear();
        for (int i = 2; i <= n; i++)
        {
            int p;
            cin >> p;
            e[p].push_back(i);
        }
        cout << n+m << '\n';
    }
    return 0;
}
