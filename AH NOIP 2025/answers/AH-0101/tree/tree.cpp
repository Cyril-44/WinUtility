#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int ans=0;
int n,m,d[maxn],vis[maxn],head[maxn],tot,sum[maxn],maxx=-1,w[maxn],pot[maxn];
int fa[maxn];
//pot save    which son is
vector<int> child[maxn];
vector<int> t[maxn];
struct node{
	int v,nxt;
}edge[maxn];
void addedge(int u,int v)
{
	edge[++tot].v=v;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
void dfs(int u,int lb)
{
	if(vis[u]) return;
	d[u]=d[lb]+1,maxx=max(maxx,d[u]);
	t[d[u]].push_back(u);
	vis[u]=1; 
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==lb) continue;
		dfs(v,u);
	}
	return ;
}
int solve(int u,int lb)
{
	int sum=0;
	if(!child[u].size())
	{
		if(pot[u]==1){w[u]=0;return 0;}
		for(auto j:child[fa[u]])
			if(!child[j].size()) sum++;
		return w[u]=sum;
	}
	for(auto v:child[u])
	{
		sum=max(sum,solve(v,u));
	}
	ans+=sum+2;
	w[u]=sum+1;
	return w[u];
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		memset(w,0,sizeof(w));
		memset(pot,0,sizeof(pot));
		ans=0,maxx=-1;
		cin>>n>>m;
		for(int i=1;i<=n;i++) child[i].clear();
		for(int i=1;i<=n;i++) t[i].clear();
		for(int i=2;i<=n;i++)
		{
			int v;cin>>v;
			addedge(v,i);addedge(i,v);
			child[v].push_back(i);pot[i]=child[v].size();
			fa[i]=v;
		}
		dfs(1,0);//first deal with maxx-1
		solve(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
