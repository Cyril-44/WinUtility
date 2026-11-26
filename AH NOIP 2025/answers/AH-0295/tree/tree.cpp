#include <bits/stdc++.h>
using namespace std;
const int N = 8005;

int n, m, a[N];
vector<int> e[N];

/*
void dfs(int u, int f)
{
    for (int v : e[u])
    {

    }
    return;
}
*/

void sovle()
{
    cin >> n >> m;
    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    if (m <= 2)
    {
        cout << n + 1 << '\n';
        return;
    }
    cout << n + m << '\n';
    return;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) sovle();
    return 0;
}
