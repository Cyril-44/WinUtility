#include <bits/stdc++.h>
using namespace std;
const int maxn = 8010;
int n, m, fa[maxn], son[maxn], ans, maxv, a[maxn], maxt[maxn];
vector<int> G[maxn], sons[maxn];
void dfs(int u)
{
	son[u] = 1;
	int sz = G[u].size();
	for(int i=0;i<sz;i++)
	{
		int v = G[u][i];
		if(v==fa[u]) continue;
		dfs(v);
		son[u] += son[v];
	}
}
void DFS(int u)
{
	int sz = G[u].size();
	sons[u].clear();
	sons[u].push_back(u);
	for(int i=0;i<sz;i++)
	{
		int v = G[u][i];
		if(v==fa[u]) continue;
		DFS(v);
		int s = sons[v].size();
		for(int i=0;i<s;i++)
			sons[u].push_back(sons[v][i]);
	}
}
void solve()
{
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		int sz = sons[i].size();
		vector<int> s;
		for(int j=0;j<sz;j++)
			s.push_back(a[sons[i][j]]);
		sort(s.begin(),s.end());
		if(s[0]!=0) continue;
		int cnt = 0;
		for(int j=1;j<sz;j++)
		{
			if(s[j]<=s[j-1]+1)
				cnt = s[j];
			else
				break;
		}
		sum += cnt+1;
	}
	ans = max(ans, sum);
}
void ddfs(int cur)
{
	if(cur>n)
	{
		solve();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		a[cur] = i;
		ddfs(cur+1);
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ans = 0, maxv = 0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=2;i<=n;i++)
		{
			cin>>fa[i];
			G[fa[i]].push_back(i);
		}
		if(m<=2)
		{
			dfs(1);
			for(int i=2;i<=n;i++)
			{
				if(fa[i]==1)
				{
					ans += son[i];
					if(son[i]>1) ans++;
					maxv = max(maxv, son[i]);
				}
			}
			ans += maxv+1;
		}
		else if(n<=7)
		{
			DFS(1);
			ddfs(1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
