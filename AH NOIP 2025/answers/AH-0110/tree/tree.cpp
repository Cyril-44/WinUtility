#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans;
vector<int> G[1145];
bitset<1024> b[1145];
int dfs2(int u,int fa)
{
    int res=0;
    for(int v:G[u])
    {
        if(v==fa) continue;
        res+=dfs2(v,u);
        b[u]|=b[v];
    }
    for(int i=0;i<n;i++){
        if(!b[u][i]){
            res+=i;
            return res;
        }
    }
}
void dfs1(int d)
{
    if(d>n)
    {
        ans=max(ans,dfs2(1,0));
        return ;
    }
    for(int i=0;i<n;i++){
        b[d][i]=1;
        dfs1(d+1);
        b[d][i]=0;
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=2;i<=n;i++){
            int fa;cin>>fa;
            G[i].push_back(fa);
            G[fa].push_back(i);
        }
        dfs1(1);
        cout<<ans<<'\n';
        ans=0;
        for(int i=1;i<=n;i++) b[i].reset();
    }
    return 0;
}
