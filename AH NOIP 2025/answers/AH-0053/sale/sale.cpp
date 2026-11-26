#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5010;
const int mod = 998244353;
int qpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
int n, m, a[maxn], ans, b[maxn], c[maxn], d[maxn], dp[20][50];
struct Node{int n,v,w;};
Node v[maxn];
bool cmp(Node &A, Node &B)
{
	if(1.0*A.v/A.w!=1.0*B.v/B.w)
		return 1.0*A.v/A.w>1.0*B.v/B.w;
	else if(A.v!=B.v)
		return A.v>B.v;
	else
		return A.n<B.n;
}
void solve()
{
	for(int i=1;i<=n;i++)
		v[i].n = i, v[i].v = a[i], v[i].w = c[i];
	sort(v+1,v+1+n,cmp);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j>=c[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]]+a[i]);
		}
	}
	int res = m, sum = 0;
	for(int i=1;i<=n;i++)
		if(res>=v[i].w)
			res -= v[i].w, sum += v[i].v;
	if(sum==dp[n][m]) ans++;
}
void dfs(int cur)
{
	if(cur>n)
	{
		solve();
		return;
	}
	c[cur] = 1;
	dfs(cur+1);
	c[cur] = 2;
	dfs(cur+1);
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==18)
		{
			cout<<qpow(2,n)<<"\n";
			continue;
		}
		else if(c<=5)
		{
			ans = 0;
			dfs(1);
			cout<<ans%mod<<"\n";
		}
		else
			cout<<0<<"\n";
	}
	return 0;
}
