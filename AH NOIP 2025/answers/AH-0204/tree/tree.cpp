#include<cstdio>
#include<string.h>
#include<algorithm>
#define int long long
using namespace std;
struct node
{
	int v;
	int next;
};
node edge[200100];
int head[100100];
int cnt;
void add(int u,int v)
{
	cnt++;
	edge[cnt].next = head[u];
	edge[cnt].v = v;
	head[u] = cnt;
}
int sum[100100];
struct nod
{
	int h;
	int sum;
};
int vis[100100];
nod dfs(int u)
{
	vis[u] = 1;
	if(head[u] == 0)
	{
		nod x;
		x.h = 0;
		x.sum = 1;
		return x;
	}
	int hu = 0,ans = 0;
	int i;
	for(i = head[u];i;i = edge[i].next)
	{
		int v = edge[i].v;
		if(vis[v])	continue;
		nod x = dfs(v);
		//~ printf("%lld %lld\n",v,x.sum);
		hu = max(hu,x.h + 1);
		ans += x.sum;
	}
	nod x;
	x.h = hu;
	x.sum = ans + hu + 1;
	//~ printf("%lld %lld\n",u,x.sum);
	return x;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	//~ printf("bb");
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(edge,0,sizeof(edge));
		memset(head,0,sizeof(head));
		int n,m;
		scanf("%lld%lld",&n,&m);
		int i;
		for(i = 2;i <= n;i++)
		{
			int u,v = i;
			scanf("%lld",&u);
			add(u,v);
			add(v,u);
		}
		nod x = dfs(1);
		printf("%lld\n",x.sum);
	}
	return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
