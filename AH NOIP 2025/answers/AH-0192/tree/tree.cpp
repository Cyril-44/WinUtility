#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int t, n, m, fa[8001], weight[8001], value[8001], res;
vector<int> g[5][8001];
void dfs(int x)
{
	//cout << "dfs(" << x << ")\n";
	bool is_leaf = true;
	int max = -1;
	for(int son : g[t][x])
	{
		//cout << x << " -> " << son << "\n";
		is_leaf = false;
		dfs(son);
		if(max < weight[son])
			max = weight[son];
	}
	if(is_leaf)
	{
		weight[x] = weight[fa[x]] + 1;
		weight[fa[x]]++;
		if(!weight[x])	value[x] = 1;
	}
	else
		weight[x] = max + 1, value[x] = weight[x] + 1;
	//cout << "weight[" << x << "] = " << weight[x] << "\n";
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		res = 0;
		cin >> n >> m;
		memset(weight,	 0xff, sizeof(weight));
		memset(value,	 0x00, sizeof(value));
		for(int i = 2; i <= n; i++)
		{
			cin >> fa[i];
			g[t][fa[i]].push_back(i);
		}
		dfs(1);
		for(int i = 1; i <= n; i++)
			res += value[i];
		cout << res << "\n";
	}
	return 0;
}
