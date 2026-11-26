#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0; re char c;
	while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48);
	while((c=getchar())>'-');
	return x;
}
inline void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10|48);
}
const int N=8008;
int h[N],e[N],ne[N],idx,sz[N],sn[N];
long long ans=0;
inline void add(int a,int b)
{
	e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}
inline int dfs(int u)
{
	sz[u]=1;
	for(re int i=h[u];i;i=ne[i])
	{
		int v=e[i];
		sz[v]=dfs(v);
		if(sz[v]>sz[sn[u]]) sn[u]=v;
	}
}
inline void dfs1(int u)
{
	if(sn[u]) dfs1(sn[u]);
	ans+=sz[u]-1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t; cin>>t;
	while(t--)
	{
		memset(h,0,sizeof h);
		int n,m; cin>>n>>m;
		for(re int i=2;i<=n;++i)
			add(read(),i);
		dfs(1),ans=0,dfs1(1);
		cout<<ans<<'\n';
	}
	return 0;
}
