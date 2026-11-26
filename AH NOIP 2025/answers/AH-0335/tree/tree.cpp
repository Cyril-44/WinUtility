#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 15
using namespace std;
int t, n, m, ans, sum;
bool flag[MAXN][MAXN];
int a[MAXN], cnt[MAXN];
int exist[MAXN][MAXN];
vector<int> g[MAXN];
void dfs2(int x) {
    for(int i=0; i<g[x].size(); i++) {
        dfs2(g[x][i]);
        for(int j=1; j<=cnt[g[x][i]]; j++) {
            flag[x][exist[g[x][i]][j]] = true;
        }
    }
    int u = -1;
    flag[x][a[x]] = true;
    for(int i=0; i<=n; i++) {
        if(u==-1&&!flag[x][i]) {
            u = i;
        }
        if(flag[x][i]) {
            exist[x][++cnt[x]] = i;
        }
    }
    sum += u;
    return ;
}
void dfs(int x) {
    if(x>n) {
        sum = 0;
        memset(flag, false, sizeof(flag));
        memset(cnt, 0, sizeof(cnt));
        dfs2(1);
        ans = max(ans, sum);
        return ;
    }
    for(int i=0; i<n; i++) {
        a[x] = i;
        dfs(x+1);
    }
    return ;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            g[i].clear();
        }
        for(int i=2, fa; i<=n; i++) {
            cin >> fa;
            g[fa].push_back(i);
        }
        if(m==1) {
            cout << n+1 << "\n";
            continue;
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
