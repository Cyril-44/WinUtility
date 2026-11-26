 #include<bits/stdc++.h>
using namespace std;
#define popcount(x) __builtin_popcount(x)
typedef long long ll;
constexpr int N=8005,M=805;
constexpr ll mod=998244353;
vector<int>e[N];
int f[N][M],g[N][M],s[N][M];
int son[N],dep[N],dfn[N],ed[N],p[N],fa[N],n,m,t;
struct BIT{
	int v[N];
	inline void clr()
	{
		memset(v,0,n+2<<2);
	}
	inline int lowbit(const int x)
	{
		return x&(-x);
	}
	inline void add(int x,const int d)
	{
		for(;x<=n;x+=lowbit(x))
			v[x]+=d;
	}
	inline int query(int x)
	{
		int s=0;
		for(;x;x-=lowbit(x))
			s+=v[x];
		return s;
	}
}a[M];
void dfs_init(const int k)
{
	dfn[k]=++t,p[t]=k,son[k]=0;
	for(int i:e[k])
		dep[i]=dep[k]+1,dfs_init(i),son[k]=i;
	ed[k]=t;
}
void dfs(const int k)
{
	//g:
	for(int i:e[k])
		dfs(i);
	for(int i:e[k])
		for(int j=1;j<=m;++j)
			s[k][j]+=f[i][j];
	for(int i:e[k])
		for(int j=1;j<=m;++j)
			g[k][j]=max(g[k][j],s[k][j]-f[i][j]+g[i][j+1]);
	for(int j=1;j<=m;++j)
		g[k][j]+=j;
	//f:
	for(int i=1;i<=m;++i)
		f[k][i]=(ed[k]-dfn[k]+1)*i;
	f[k][1]=g[k][1];
	for(int i=1;i<=m;++i)
		a[i].add(dfn[k],s[k][i]),a[i].add(ed[k]+1,-s[k][i]);
	for(int it=dfn[k]+1;it<=ed[k];++it)
	{
		int i=p[it],j=dep[i]-dep[k]+1;
	//	h[i][j]=h[son[i]][j]+f[son[i]][j]-s[i][j]+s[k][j];
		f[k][j]=max(f[k][j],a[j].query(it)+g[i][j]-s[i][j]+j*(j-1));
	}
	for(int i=1;i<=m;++i)
		a[i].add(dfn[k],-f[k][i]),a[i].add(ed[k]+1,f[k][i]);
	/*for(int it=dfn[k];it<=ed[k];++it)
	{
		int i=p[it],j=dep[i]-dep[k]+1;
		h[i][j]-=f[k][j];
	}*/
//	for(int i=1;i<=m;++i)
	//	cerr<<k<<' '<<i<<':'<<f[k][i]<<'\n';
}
void solve()
{
	memset(s,0,sizeof s),memset(g,0,sizeof g),memset(f,0,sizeof f),t=0;
	cin>>n>>m,++m;
	for(int i=1;i<=m;++i)
		a[i].clr();
	for(int i=1;i<=n;++i)
		e[i].clear();
	for(int i=2;i<=n;++i)
		cin>>fa[i],e[fa[i]].push_back(i);
	dfs_init(1);
	dfs(1);
	//cerr<<f[3][2]<<'\n';
	cout<<g[1][1]<<'\n';
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
