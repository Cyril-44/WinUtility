#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 16010;

typedef long long LL;
typedef pair<LL, LL> PII;

int T, n, m;
LL ans, tmp;
int h[N], e[N], ne[N], w[N], idx;
int son[N];

void add(int u, int v)
{
	e[idx] = v, ne[idx] = h[u], h[u] = idx ++;
}

int calc(int u)
{
	int ch = 0, mex = 0;
	vector<int> v;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i]; ch ++;
		int t = calc(j);
		mex = max(mex, t);
		v.push_back(w[j]);
	}
	
	if(ch == 0)
	{
		if(w[u] == 0) mex = 1;
		else mex = 0;
		tmp += mex;
		return mex;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i ++ )
		if(v[i] == mex) mex ++;
	w[u] = mex; mex ++;
	tmp += mex;
	return mex;
}

void dfs(int u)
{
	if(u > n)
	{
		tmp = 0;
		
		calc(1);
		ans = max(ans, tmp);
		return;
	}
	if(son[u] != 0) dfs(u + 1);
	for (int i = 0; i < n; i ++ )
	{
		w[u] = i;
		dfs(u + 1);
	}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	scanf("%d", &T);
	while (T -- )
	{
		memset(h, -1, sizeof h);
		
		scanf("%d%d", &n, &m);
		for (int i = 2; i <= n; i ++ )
		{
			int fa;
			scanf("%d", &fa);
			add(fa, i);
			son[fa] ++;
		}
		if(n <= 7)
		{
			ans = 0;
			dfs(1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
