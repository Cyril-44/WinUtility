#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=365;
// const int N=8e3+5; 
int n,m; vector<int> v[N];
int dp[N][N][N],sz[N],f[N][N],g[N][N];
void upd(int &x,int y) { x=max(x,y); }

void Upd(int pos,int p) {
    for(int i=0;i<=sz[pos];++i) for(int j=0;j<=p;++j) f[i][j]=dp[pos][i][j];
    for(int i=0;i<=sz[pos];++i) for(int j=1;j<=p;++j) upd(f[i][j],f[i][j-1]); 
}
void dfs(int pos) {
    dp[pos][1][0]=0; sz[pos]=1;
    for(auto u:v[pos]) {
        dfs(u); int mx=max(sz[pos],sz[u]);
        for(int i=0;i<=sz[pos]+sz[u];++i) for(int j=0;j<=mx;++j) g[i][j]=-n*n;
        Upd(pos,mx);
        for(int i=0;i<=sz[u];++i) for(int j=0;j<=sz[pos];++j) for(int k=0;k<=mx;++k) upd(g[i+j][k],dp[u][i][k]+f[j][k]);
        Upd(u,mx);
        for(int i=0;i<=sz[pos];++i) for(int j=0;j<=sz[u];++j) for(int k=0;k<=mx;++k) upd(g[i+j][k],dp[pos][i][k]+f[j][k]);
        for(int i=0;i<=sz[pos]+sz[u];++i) for(int j=0;j<=mx;++j) dp[pos][i][j]=g[i][j]; sz[pos]=sz[pos]+sz[u];
    }
    for(int i=sz[pos];i;--i) for(int j=0;j<=sz[pos];++j) upd(dp[pos][i-1][j+1],dp[pos][i][j]);
    for(int i=0;i<=sz[pos];++i) for(int j=0;j<=sz[pos];++j) if(dp[pos][i][j]>=0) dp[pos][i][j]=dp[pos][i][j]+j;
}

void wk() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) v[i].clear();
    for(int i=2,x;i<=n;++i) cin >> x,v[x].pb(i);
    for(int i=1;i<=n;++i) for(int j=0;j<=n;++j) for(int k=0;k<=n;++k) dp[i][j][k]=-n*n;
    dfs(1);
    int ans=0; for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) upd(ans,dp[1][i][j]); 
    cout << ans << "\n";
}   

signed main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    ios::sync_with_stdio(false);

    int t; cin >> t;

    for(;t--;) wk();

    return 0;
}