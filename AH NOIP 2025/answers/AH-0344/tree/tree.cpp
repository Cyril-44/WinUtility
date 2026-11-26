#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 8005;
vector<ll> son[N];
ll dep[N], fa[N], siz[N], tson[N];
ll n, ans;
void dfs(ll u)
{
    siz[u] = 1;
    for (ll v : son[u])
    {
        dep[v] = dep[u] + 1;
        dfs(v);
        siz[u] += siz[v];
        if (siz[tson[u]] < siz[v]) tson[u] = v;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) son[i].clear();
    memset(siz, 0, sizeof siz);
    //
    cin >> n;
    cin >> dep[1];
    dep[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        son[fa[i]].push_back(i);
    }
    dfs(1);
    ans = 0;
    ll t = 1;
    while (son[t].size())
    {
        ans += siz[t];
        t = tson[t];
    }
    ans += siz[t];
    //
    // for (int i = 1; i <= n; i++) cout << tson[i];
    cout << ans;
    cout << '\n';
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}