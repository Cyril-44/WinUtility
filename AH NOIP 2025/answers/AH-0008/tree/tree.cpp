#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4010;
vector<int> g[N];
int n,m,fa;
// int f[20][1<<18],tmp[1<<18],sz[N];
// vector<int> val[N];
// int lowbit(int x){return x&-x;}
// void dfs(int u){
//     sz[u]=1;
//     for(int i=0;i<n;i++)
//         f[u][1<<i]=0;
//     for(int v:g[u]){
//         dfs(v);
//         for(int i:val[sz[u]+sz[v]]) tmp[i]=0;
//         for(int i:val[sz[u]])
//             for(int j:val[sz[v]])
//                 tmp[i|j]=max(tmp[i|j],f[u][i]+f[v][j]);
//         for(int i:val[sz[u]+sz[v]]) f[u][i]=tmp[i];
//         sz[u]+=sz[v];
//     }
//     for(int i:val[sz[u]])
//         f[u][i]+=__lg(lowbit((1<<20)-1-i));
// }
const int M=365;
int f[M][M][M],tmp[M][M],sz[M];
void upd(int &x,int y){
    if(x<y) x=y;
}
void dfs(int u){
    // cerr<<u<<endl;
    f[u][0][1]=0;
    sz[u]=1;
    for(int v:g[u]){
        dfs(v);
        for(int i=0;i<=sz[u]+sz[v];i++)
            for(int j=0;i+j<=sz[u]+sz[v];j++)
                tmp[i][j]=0xc0c0c0c0;
        for(int i=0;i<=sz[u];i++)
            for(int j=0;i+j<=sz[u];j++)
                for(int k=0;k<=sz[v];k++)
                    for(int l=0;k+l<=sz[v];l++)
                        upd(tmp[max(i,k)][j+l],f[u][i][j]+f[v][k][l]);
        sz[u]+=sz[v];
        for(int i=0;i<=sz[u];i++)
            for(int j=0;i+j<=sz[u];j++)
                f[u][i][j]=tmp[i][j];
    }
    for(int i=0;i<=sz[u];i++)
        for(int j=0;i+j<=sz[u];j++)
            f[u][i][j]+=i;
    for(int j=sz[u]-1;j>=0;j--)
        for(int i=1;i+j<=sz[u];i++)
            upd(f[u][i][j],f[u][i-1][j+1]+1);
    // printf("%d\n",u);
    // for(int i=0;i<=sz[u];i++){
    //     for(int j=0;i+j<=sz[u];j++)
    //         printf("%d ",f[u][i][j]);
    //     putchar('\n');
    // }
    // cerr<<"back "<<u<<' '<<sz[u]<<endl;
}
void work(){
    scanf("%d%d",&n,&m);
    // for(int i=0;i<=n;i++) val[i].clear();
    // for(int i=0;i<(1<<n);i++)
    //     val[__builtin_popcount(i)].push_back(i);
    // for(int i=1;i<=n;i++){
    //     for(int x:val[i-1])
    //         val[i].push_back(x);
    // }
    // if(n<=18){//30pts
    // cerr<<"HERE"<<endl;
    if(n<=360){
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=2;i<=n;i++)
            scanf("%d",&fa),g[fa].push_back(i);
        memset(f,0xc0,sizeof(f));
        // cerr<<"HERE"<<endl;
        dfs(1);
        int ans=0;
        for(int i=0;i<=n;i++)
            ans=max(ans,f[1][i][0]);
        printf("%d\n",ans); 
        // cerr<<"HERE"<<endl;
    }
}
int t;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        work();
    }
    return 0;
}