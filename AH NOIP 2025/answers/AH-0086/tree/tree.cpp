#include<bits/stdc++.h>
using namespace std;
int t,n,m,fa[8011];
vector<int> a[8011];
int f[8011][361],de[8011],g[8011],son[8011],w[8011];
int dd(int u,int fa)
{
    son[u]=de[u]=1;
    for(int w=0;w<a[u].size();w++)
    {
        int v=a[u][w];
        son[u]+=dd(v,u);
        de[u]=max(de[u],de[v]+1);
    }
    return son[u];
}
int dfs(int u,int fa,int dep)
{
    bool flag=0;
    int maw=0;
    f[u][0]=1;
    for(int q=0;q<a[u].size();q++)
    {
        int v=a[u][q];
        int x=dfs(v,u,dep+1);
        for(int i=0;i<son[u];i++)
            for(int j=0;j<=min(son[v],i);j++)
            {
                    f[u][i]=max(f[u][i],f[v][j]+i+1);
                    f[u][i]=max(f[u][i],g[v]+i+1-(son[v]-x));
            }
      //  f[u][0]=f[v][0]+son[u]+1;
        g[u]+=f[v][son[v]-1];
        w[u]+=g[v];
        maw=max(maw,son[v]);
    }
    g[u]+=maw+1;
    w[u]+=de[u];
    g[u]=max(g[u],w[u]);
    /*if(u==1){
    printf("%d : \n",u);
    for(int i=0;i<=son[u];i++) printf("%d ",f[u][i]);
    printf("%d \n",g[u]);}*/
    return maw+1;
}
int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(de,0,sizeof(de));
        memset(son,0,sizeof(son));
        memset(w,0,sizeof(w));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&fa[i]);
            a[fa[i]].push_back(i);
        }
        dd(1,0);
        //for(int i=1;i<=n;i++) printf("%d\n",de[i]);
        dfs(1,0,1);
        int ans=g[1];
        for(int i=0;i<=son[1];i++) ans=max(ans,f[1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
