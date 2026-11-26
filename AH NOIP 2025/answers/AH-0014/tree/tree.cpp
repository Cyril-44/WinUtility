/*

   * Happy Zenith Noises *

         2025.11.29

*/
#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int>P;
const int MAXN=100005;
int n,m,dep[MAXN],fa[MAXN],s[MAXN],si[MAXN],mx,ans;
int f[2][125][125][125];
vector<int>g[MAXN];
void dfs(int x){
    s[dep[x]]++;si[x]=1;
    for(int i:g[x]){
        dep[i]=dep[x]+1;
        dfs(i);si[x]+=si[i];
    }
    if(si[x]>1&&x!=1)ans+=1+si[x];
    else if(dep[x]==1&&si[x]==1)ans++;
    if(x!=1)mx=max(mx,si[x]);
}
void dp(int x){
    if(g[x].size()==0){
        f[0][x][0][1]=0;
        f[0][x][1][0]=1;
        return ;
    }
    int ts=1;
    f[0][x][0][1]=0;int lst,now=0;
    for(int i:g[x]){
        dp(i);
        lst=now;now=1-now;
        memset(f[now][x],-0x3f,sizeof(f[now][x]));
        for(int j=0;j<=si[i];j++){
            for(int _j=0;_j<=ts;_j++){
                for(int k=0;k<=ts;k++){
                    for(int t=0;t<=si[i];t++){
                        if(f[0][i][j][t]<0)continue;
                        f[now][x][max(j,_j)][k+t]=
                        max(f[now][x][max(j,_j)][k+t],f[lst][x][_j][k]+f[0][i][j][t]);
                    }
                }
            }
        }
        ts+=si[i];
    }
    lst=now,now=1-now;
    memset(f[now][x],-0x3f,sizeof(f[now][x]));
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=j;k++)
        f[now][x][i+k][j-k]=max(f[now][x][i+k][j-k],f[lst][x][i][j]+i+k);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[0][x][i][j]=f[now][x][i][j];
}
void solve(){
    cin>>n>>m;mx=0;ans=0;
    for(int i=0;i<=n;i++)g[i].clear(),s[i]=0,si[i]=0;
    for(int i=2;i<=n;i++)cin>>fa[i],g[fa[i]].pb(i);
    dfs(1);
    if(m==1){
        cout<<n+1<<'\n';
        return ;
    }
    if(m==2){
        cout<<ans+mx+1<<'\n';
        return ;
    }
    memset(f,-0x3f,sizeof(f));
    dp(1);
    ans=0;
    for(int i=0;i<=n+1;i++)for(int j=0;j<=n;j++)ans=max(ans,f[0][1][i][j]);
    cout<<ans<<'\n';
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}

