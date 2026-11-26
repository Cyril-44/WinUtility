#include <bits/stdc++.h>
#define maxn 8010
using namespace std;
int T,n,m;
int fa[maxn];
int tot,to[maxn],h[maxn],nxt[maxn];
int soncnt[maxn];
int val[maxn];
int deep[maxn];
int leavef[maxn];
int ans;
void add(int u,int f)//fa->son
{
    tot++;
    to[tot]=u;nxt[tot]=h[f];h[f]=tot;
}
void dfs(int u,int f)
{
    if(soncnt[u]==0)
    {
        val[u]=leavef[f];
        leavef[f]++;
        return;
    }
    for(int i=h[u];i;i=nxt[i])
    {
        dfs(to[i],u);
        val[u]=max(val[u],val[to[i]]+1);
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n>>m;
        memset(soncnt,0,sizeof(soncnt));
        memset(to,0,sizeof(to));
        memset(h,0,sizeof(h));
        memset(nxt,0,sizeof(nxt));
        memset(deep,0,sizeof(deep));
        memset(leavef,0,sizeof(leavef));
        tot=0;
        ans=0;
        for(int i=2;i<=n;i++)
        {
            cin>>fa[i];
            add(i,fa[i]);
            soncnt[fa[i]]++;
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            if(soncnt[i]==0)
                ans+=(val[i]==0)? 1:0;
            else
                ans+=val[i]+1;
        }
        cout<<ans<<endl;
    }

	return 0;
}

