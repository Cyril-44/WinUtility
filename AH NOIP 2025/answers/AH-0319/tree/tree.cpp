#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
const int N=8010;
int n,m,ans;
vector<int>G[N];
int f[20][1<<18],g[1<<18];
void merge(int v,int u)
{
    for(int i=0;i<(1<<n);i++)g[i]=f[u][i];
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
            f[u][i|j]=max(f[u][i|j],g[i]+f[v][j]);
}
void dfs(int x)
{
    for(int i=0;i<(1<<n);i++)f[x][i]=-inf;
    for(int i=0;i<n;i++)f[x][(1<<i)]=0;
    for(auto y:G[x])
    {
        dfs(y);
        merge(y,x);
    }
    for(int i=0;i<(1<<n);i++)
    {
        if(i==(1<<n)-1)f[x][i]+=n;
        else
        for(int j=0;j<n;j++)
            if(((i>>j)&1)^1)
            {
                f[x][i]+=j;
                break;
            }

    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        G[u].emplace_back(i);
    }
    dfs(1);
    ans=0;
    for(int i=1;i<(1<<n);i++)ans=max(ans,f[1][i]);
    cout<<ans<<"\n";
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
