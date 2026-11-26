#include <bits/stdc++.h>
using namespace std;
int t,p[8005],depth[8005];
vector<int> e[800005];
void dfs(int u)
{
	for(auto v : e[u])
	{
		if(v == p[u]) continue;
		depth[u] = depth[v] + 1;
		dfs(v);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		int n,m;
		long long ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
			e[i].push_back(p[i]);
			e[p[i]].push_back(i);
		}
		dfs(1);
		for(int i = 1; i <= n; i++)
		{
			ans += depth[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
