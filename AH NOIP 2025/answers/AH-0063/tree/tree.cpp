#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll T,n,m;
vector<int> g[8005];
int c[8005];//include x
int dfs(int x,int fa)
{
    int cnt=0;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==fa)
            continue;
        cnt+=dfs(v,x);
    }
    return c[x]=cnt+1;
}
ll ans;
bool check(int x,int fa)
{
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==fa)
            continue;
        if(c[v]!=1)
            return false;
    }
    return true;
}
ll dfs2(int x,int fa)//0-?
{
    ll mx=-1;
    ll cnt1=0;
    if(check(x,fa))
    {
        ans+=c[x]+1;
        return c[x]-1;
    }
    for(int i=0;i<g[x].size();i++)//有两种方法:1.冒险(高收益) 2.不冒险
    {
        int v=g[x][i];
        if(v==fa)
            continue;
        if(c[v]==1)
        {
            cnt1++;
            continue;
        }
        mx=max(mx,dfs2(v,x));
    }
    if(cnt1>=1)
    {
        ans+=mx+cnt1+2;
        return mx+cnt1+1;
    }
    ans+=mx+2;
    //cout<<"x:"<<x<<" fa:"<<fa<<" ans:"<<mx+1<<"\n";
    return mx+1;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(c,0,sizeof(c));
        ans=0;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1,v;i<n;i++)
        {
            scanf("%d",&v);
            g[i+1].push_back(v);
            g[v].push_back(i+1);
        }
        dfs(1,0);
        dfs2(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
