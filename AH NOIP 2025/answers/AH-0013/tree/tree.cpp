#include<bits/stdc++.h>
using namespace std;
//背包出f[u][i0][j0]转移到f[u][nowx][j0-(nowx-i0)]
//f[u][i][j]表示u子树填好0~i-1，留了至少j个点没填的最大价值
const int N=8005,inf=1e9;
int T,n,m,fa[N],sz[N],tf[N][N];
int tot,fi[N],ne[N<<1],to[N<<1];
vector<vector<int>> f[N];
void add(int x,int y){
    to[++tot]=y;ne[tot]=fi[x];fi[x]=tot;
}
void chkmax(int &x,int y){if(y>x)x=y;}
void init(){
    tot=0;memset(fi+1,0,n*sizeof(int));
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
        scanf("%d",&fa[i]);
        add(fa[i],i);
    }
}
void dfs1(int u){
    sz[u]=1;
    for(int i=fi[u];i;i=ne[i]){
        int v=to[i];
        dfs1(v);sz[u]+=sz[v];
    }
    f[u].resize(sz[u]+1);
    for(int i=0;i<=sz[u];i++){
        f[u][i].resize(sz[u]-i+1);
        for(int &x:f[u][i])x=-inf;
    }
}
void dfs(int u){
    f[u][0][1]=f[u][1][0]=0;sz[u]=1;
    for(int i=fi[u];i;i=ne[i]){
        int v=to[i];
        dfs(v);
        for(int p=0;p<=sz[u]+sz[v];p++)
            for(int j=0;j+p<=sz[u]+sz[v];j++)
                tf[p][j]=-inf;
        for(int p1=0;p1<=sz[u];p1++)
            for(int j=0;j+p1<=sz[u];j++)
                if(f[u][p1][j]!=-inf)
                    for(int p2=0;p2<=sz[v];p2++)
                        for(int k=0;k+p2<=sz[v];k++)
                            if(f[v][p2][k]!=-inf)
                                chkmax(tf[max(p1,p2)][j+k],f[u][p1][j]+f[v][p2][k]);
        sz[u]+=sz[v];
        for(int p=0;p<=sz[u];p++)
            for(int j=0;j+p<=sz[u];j++)
                f[u][p][j]=tf[p][j];
    }
    for(int p=0;p<=sz[u];p++)
        for(int i=0;i+p<=sz[u];i++)
            tf[p][i]=-inf;
    for(int p=0;p<=sz[u];p++)
        for(int i=0;i+p<=sz[u];i++)
            if(f[u][p][i]!=-inf)
                for(int nowx=p;nowx-p<=i;nowx++)
                    chkmax(tf[nowx][i-(nowx-p)],f[u][p][i]);
    for(int p=0;p<=sz[u];p++)
        for(int i=0;i+p<=sz[u];i++)
            if(tf[p][i]!=-inf)f[u][p][i]=tf[p][i]+p;
}
void work(){
    dfs1(1);dfs(1);
    int ans=-inf;
    for(int i=0;i<=n;i++)
        for(int j=0;i+j<=n;j++)
            ans=max(ans,f[1][i][j]);
    printf("%d\n",ans);
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        init();
        work();
    }
}
/*
Birds just don't fly,they fall down and get up.
Nobody learns without getting it wrong.
*/