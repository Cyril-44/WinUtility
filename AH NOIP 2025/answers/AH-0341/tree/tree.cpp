#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll T,n,m,fa[N],mex[N],ans,siz[N],son[N];
vector<ll> g[N];
void dfs(ll u,ll f)
{
    siz[u]=1;
    for(int v:g[u])
    {
        if(v!=f)dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void dfs_ans(ll u)
{
    //cout<<son[u]<<"";
    if(siz[u]==1)
    {
        ans++;
        return;
    }
    if(siz[son[u]]==1)
    {
        mex[u]=siz[u];
        ans++;
        return;
    }
    else
    {
        dfs_ans(son[u]);
        mex[u]=mex[son[u]]+1;
        for(auto v:g[u])
        {
            if(v!=son[u])dfs_ans(v);
        }
    }
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=2;i<=n;i++)
        {
            cin>>fa[i];
            g[fa[i]].push_back(i);
        }
        dfs(1,0);
        dfs_ans(1);
        for(int i=1;i<=n;i++)
        {
            //cout<<mex[i]<<" ";
            g[i].clear();
            ans+=mex[i];
        }
        cout<<ans<<"\n";
        ans=0;
        memset(mex,0,sizeof(mex));
        memset(son,0,sizeof(son));
    }
    return 0;
}
