#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 8005;
vector <int> G[N];
int n, m, tt;
int mex[N];
int v[N];
void dfs(int now, int fa) {
    if(G[now].size() == 1 && fa) {
        mex[now] = 0;
        return ;
    }
    for (auto u : G[now]) {
        if(u == fa) continue ;
        dfs(u, now);
        mex[now] = max(mex[now], mex[u]);
    }
    int cnt = mex[now] + 1, flag = 0;
    for (auto u : G[now]) {
        if(u == fa) continue ;
        if(mex[u] == mex[now] && !flag) v[u] = mex[u], flag = 1;
        else v[u] = cnt, cnt ++;
    }
    mex[now] = cnt;
}
void solve() {
    memset(mex, 0, sizeof(mex));
    dfs(1, 0);
    int ans = 0;
    v[1] = mex[1];
    for (int i = 1; i <= n; i ++) {
        ans += (v[i] == mex[i] ? mex[i] + 1 : mex[i]);
    }
    cout << ans << endl;
}
signed main(void) {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tt;
    while (tt --) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++) G[i].clear();
        for (int i = 2; i <= n; i ++) {
            int u;
            cin >> u;
            G[u].emplace_back(i);
            G[i].emplace_back(u);
        }
        solve();
    }
    return 0;
}
