#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,f[8005][8005],sz[8005],dp[8005][8005],m,dp2[8006][8005];
vector<int> g[8005];
void dfs(int x){
    sz[x]=1;
    for(auto v:g[x]){
        dfs(v);
        sz[x]+=sz[v];
    }
    for(int i=0;i<=sz[x];i++)
        for(int j=0;j<=sz[x];j++) dp[i][j]=-1;
    dp[sz[x]][0]=0;
    int s=0,mx=0;
    for(auto v:g[x]){
        for(int i=0;i<=sz[x];i++)
            for(int j=0;j<=mx;j++) dp2[i][j]=dp[i][j],dp[i][j]=0;
        for(int i=0;i<=s;i++){
            for(int j=0;j<=mx;j++){
                for(int l=0;l<=sz[v];l++){
                    if(dp2[sz[x]-i+j][j]!=-1&&f[v][l]!=-1)
                        dp[sz[x]-i-l+max(j,l)][max(j,l)]=max(dp[sz[x]-i-l+max(j,l)][max(j,l)],dp2[sz[x]-i+j][j]+f[v][l]);
                }
            }
        }
        mx=max(mx,sz[v]);
        s+=sz[v];
    }
    for(int i=0;i<=sz[x];i++){
        for(int j=0;j<=sz[x];j++)
            f[x][i]=max(f[x][i],dp[i][j]+i);
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=2;i<=n;i++){
            int fa;
            cin>>fa;
            g[fa].push_back(i);
        }
        for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
        dfs(1);
        int ans=0;
        for(int i=0;i<=sz[1];i++) ans=max(ans,f[1][i]);
        cout<<ans<<'\n';
    }
    return 0;
}
