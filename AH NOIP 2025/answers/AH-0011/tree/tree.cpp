#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define mk make_pair
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return a>b?a:b;}
void chkmax(ll &x,ll y){if(y>x) x=y;}
const int N=125,M=805;
const ll inf=1e18+7;
int T,n,m,fa[N];
struct edges{int to,next;}edge[N];
int head[N],kk,sz[N];
void insert(int a,int b){edge[++kk]=(edges){b,head[a]};head[a]=kk;}
ll dp[N][N][N],tmp[N][N],t2[N][N],p[N][N],p2[N][N];
void dfs(int u,int fa){
    sz[u]=1,dp[u][1][0]=0;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;if(v==fa) continue;
        dfs(v,u);
        for(int j=0;j<=sz[u];++j) for(int k=0;k<=sz[u];++k){
            tmp[j][k]=dp[u][j][k],p[j][k]=mx(k?p[j][k-1]:-inf,tmp[j][k]);
            dp[u][j][k]=-inf;
        }
        for(int j=0;j<=sz[v];++j) for(int k=0;k<=sz[v];++k){
            t2[j][k]=dp[v][j][k];
            p2[j][k]=mx(k?p2[j][k-1]:-inf,t2[j][k]);
        }
        for(int j=0;j<=sz[u];++j) for(int x=0;x<=sz[v];++x) for(int k=0;k<=mx(sz[u],sz[v]);++k){
            if(k<=sz[u]) chkmax(dp[u][j+x][k],tmp[j][k]+p2[x][mn(sz[v],k)]);
            if(k<=sz[v]) chkmax(dp[u][j+x][k],p[j][mn(sz[u],k)]+t2[x][k]);
        }
        sz[u]+=sz[v];
    }
    for(int j=0;j<=sz[u];++j) for(int k=0;k+j<=sz[u];++k) tmp[j][k]=dp[u][j][k],dp[u][j][k]=-inf;
    for(int j=0;j<=sz[u];++j) for(int k=0;k+j<=sz[u];++k) for(int x=0;x<=j;++x) chkmax(dp[u][j-x][k+x],tmp[j][k]);
    for(int j=0;j<=sz[u];++j) for(int k=0;k+j<=sz[u];++k) dp[u][j][k]+=k;
    
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    in(T);
    memset(dp,-0x3f,sizeof(dp));
    while(T--){
        in(n),in(m);
        memset(head,0,sizeof(head)),kk=0;
        for(int i=2;i<=n;++i) in(fa[i]),insert(fa[i],i);
        dfs(1,0);
        ll ans=0;
        for(int j=0;j<=n;++j) for(int k=1;k+j<=n;++k) ans=mx(ans,dp[1][j][k]);
        printf("%lld\n",ans);
        memset(dp,-0x3f,sizeof(dp));
    }
    return 0;
}