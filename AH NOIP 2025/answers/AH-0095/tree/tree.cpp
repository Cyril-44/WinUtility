#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5,INF=0x3f3f3f3f;
int i,n,m,T,fa[N],u,v,ye[N],sum[N],d[N],ans,dee;
vector<int>g[N];
void pre(int u,int fa)
{
	d[u]=d[fa]+1,dee=max(dee,d[u]);
	if(g[u].size()==0)ye[u]=1;
	for(auto v:g[u])pre(v,u);
}
void dfs(int fa,int u)
{
	int ma=-1,tot=0;
	d[u]=d[fa]+1;
	if(ye[u]==1)
	{
		//cout<<"yezi"<<u<<endl;
		sum[u]=1;
		return;
	}
	for(auto v:g[u])
	{
		dfs(u,v);
		ma=max(ma,sum[v]);
		if(ye[v]==1)tot++;
	}
	if(d[u]==dee-1)sum[u]=g[u].size()+1,ans++;
	else sum[u]=ma+1,ans+=tot;
	ans+=sum[u];
	//cout<<u<<' '<<sum[u]<<' '<<ans<<endl;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)sum[i]=0,ye[i]=0;
		for(i=1;i<=n;i++)g[i].clear();
		fa[1]=0,d[0]=-1;
		for(i=2;i<=n;i++)
		{
			cin>>fa[i];
			g[fa[i]].push_back(i);
		}
		pre(1,0);
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}

