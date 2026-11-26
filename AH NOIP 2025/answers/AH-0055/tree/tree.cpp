#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,fa[40],plan[40],ans=0;
vector<int> g[40];
bool b[40][40];
inline int check(int k)
{
	b[k][plan[k]]=1;
	int res=0;
	for(auto i:g[k])
	{
		res+=check(i);
		for(int j=0;j<=m;++j)b[k][j]=b[k][j]||b[i][j];
	}
	int i=0;
	for(i=0;i<=m+1;++i)
	{
		if(b[k][i]==0)break;
	}
	res+=i;
	return res;
}
inline void dfs(int k)
{
	if(k==n+1)
	{
		memset(b,0,sizeof b);
		int res=check(1);
		if(res>ans)
		{
			ans=res;
			/*for(int i=1;i<=n;++i)
			{
				printf("%lld ",plan[i]);
			}
			puts("");*/
		}
		return;
	}
	for(int i=0;i<=m;++i)
	{
		plan[k]=i;
		dfs(k+1);
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&m);
		m=m+2;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=2;i<=n;++i)
		{
			scanf("%lld",&fa[i]);
			g[fa[i]].push_back(i);
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
