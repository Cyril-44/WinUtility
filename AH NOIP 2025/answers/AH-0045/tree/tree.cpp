#include <bits/stdc++.h>
using namespace std;
#define len 101000
int v[len];
int n, m, f[len], a[len], s[len], zss[len], ans;
int fwans[len];
vector <int> son[len], zs[len];
void csh(int x) {
    zss[x]=1, zs[x].push_back(x);
    for(int i=0;i<s[x];i++) {
        csh(son[x][i]), zss[x]+=zss[son[x][i]];
        for(int j=0;j<zss[son[x][i]];j++)
            zs[x].push_back(zs[son[x][i]][j]);
    }
    return;
}
void dfs(int x) {
    if(x==0) {
        int ts=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<n;j++) v[j]=0;
            for(int j=0;j<zs[i].size();j++) v[a[zs[i][j]]]=1;
            for(int j=0;j<n;j++) if(!v[j]) {ts+=j; break;}
        }
        if(ts>ans) {
            ans=ts;
            for(int i=1;i<=n;i++) fwans[i]=a[i];
        }
        return;
    }
//    for(int i=0;i<n;i++) a[x]=i, dfs(x-1);
    for(int i=0;i<n;i++) if(!(s[x]&&i==a[son[x][0]])) a[x]=i, dfs(x-1);
    return;
}
void solve() {
    for(int i=1;i<=n;i++) s[i]=0, son[i].clear(), zs[i].clear();
    cin>>n>>m, ans=0;
    for(int i=2;i<=n;i++) cin>>f[i], s[f[i]]++, son[f[i]].push_back(i);
    if(n<=7) csh(1), dfs(n), cout<<ans<<endl;
    return;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
/*
12
18
8
22
12
*/
