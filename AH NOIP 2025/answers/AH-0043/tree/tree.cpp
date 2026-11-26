//exam: tree
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define int long long
#define OI "tree"
using namespace std;
const int MAXN = 8005;
void dfs(int);
vector< vector<int> > g;
int mex[MAXN], a[MAXN];
int t, n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef OI
    freopen(OI ".in", "r", stdin);
    freopen(OI ".out", "w", stdout);
    #endif // OI

    cin >> t;
    while(t--) {
        memset(mex, 0, sizeof(mex));
        memset(a, 0, sizeof(a));

        cin >> n >> m;

        g.clear();
        g.resize(n + 1);

        for(int u = 2, fa; u <= n; u++) {
            cin >> fa;
            g[fa].push_back(u);
        }

        dfs(1);

        int res = 0;
        for(int i = 1; i <= n; i++) {
            //cout << i << ":" << a[i] << " " << mex[i] << endl;
            res += mex[i];
        }

        cout << res << endl;
    }
    return 0;
}
void dfs(int u) {
    int maxn = 1;
    for(auto v : g[u]) {
        dfs(v);
        maxn = max(maxn, mex[v]);
    }

    int t = maxn - 1;
    bool flag = false;
    for(auto v : g[u]) {
        if(flag || mex[v] != maxn) {
            a[v] = ++t;
            mex[v]--;
        } else {
            flag = true;
        }
    }

    a[u] = maxn - 1 + g[u].size();
    mex[u] = a[u] + 1;
}
