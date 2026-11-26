#include<cstdio>
#include<queue>
#include<string.h>
#define int long long
using namespace std;
int a[20];
int b[20];
int n,m;
const int mod = 998244353;
struct node
{
	int x;
	int y;
};
struct cmp
{
	bool operator()(node x,node y)
	{
		if(x.x * y.y != y.x * x.y)	return x.x * y.y < y.x * x.y;
		return x.x < y.x;
	}
};
priority_queue<node,vector<node>,cmp> q;
int s[30];
int ans;
void dfs(int u)
{
	if(u > n)
	{
		int mm = m;
		int i,j;
		for(i = 1;i <= n;i++)
		{
			node x;
			x.x = a[i];
			x.y = b[i];
			q.push(x);
			//~ printf("%lld ",b[i]);
		}
		//~ printf("\n");
		int s1 = 0;
		while(!q.empty())
		{
			node x = q.top();
			q.pop();
			if(x.y > m)	continue;
			s1 += x.x;
			m -= x.y;
		}
		m = mm;
		int s2 = 0;
		memset(s,0,sizeof(s));
		for(i = 1;i <= n;i++)
		{
			for(j = m;j - b[i] >= 0;j--)
			{
				if(a[i] + s[j - b[i]] > s[j])
				{
					s[j] = a[i] + s[j - b[i]];
				}
				if(s[j] > s2)	s2 = s[j];
			}
		}
		m = mm;
		//~ printf("%lld %lld\n",s1,s2);
		if(s2 == s1)	ans++;
		return ;
	}
	b[u] = 1;
	dfs(u + 1);
	b[u] = 2;
	dfs(u + 1);
}
int pow(int n,int m)
{
	int ans = 1;
	while(m)
	{
		if(m & 1)
		{
			ans *= n;
			ans %= mod;
		}
		n *= n;
		n %= mod;
		m >>= 1;
	}
	return ans;
}
long long d[100100];
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		//~ memset(b,0,sizeof(b));
		ans = 0;
		//~ int n,m;
		scanf("%lld%lld",&n,&m);
		int i;
		int x;
		int flag = 1;
		for(i = 1;i <= n;i++)
		{
			//~ int x;
			scanf("%lld",&d[i]);
			a[i] = d[i];
			if(i == 1)	x = a[i];
			else if(a[i] != x)	flag = 0;
		}
		//~ printf("a");
		if(flag)
		{
			printf("%lld\n",pow(2,n));
			continue;
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
3 2
1 3 5
*/
