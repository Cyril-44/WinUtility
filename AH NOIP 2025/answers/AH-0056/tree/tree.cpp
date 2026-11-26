#include<bits/stdc++.h>
using namespace std;
int T=0;
struct edge{
    int nxt,to;
}e[8005];
int h[8005],cnt;
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=h[u];
    h[u]=cnt;
}
int fa[8005];
int sum[8005];
void dfs(int u,int f){
    sum[u]=1;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].to;
        dfs(v,u);
        sum[u]+=sum[v];

    }
}
int f[8005];
void dfs2(int u){
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].to;
        dfs2(v);
        f[u]=max(f[u],f[v]);
    }
    f[u]+=sum[u];
}
int n,m;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        for(int i=1;i<=n;i++)h[i]=sum[i]=f[i]=0;
        cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=2;i<=n;i++){
            scanf("%d",&fa[i]);
            add(fa[i],i);
        }
        dfs(1,0);
        dfs2(1);
        printf("%d\n",f[1]);

    }
}
