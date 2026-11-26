#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=5e4+10;
const double eps=0.0000000000000001;
int c,t,n,m,w[maxn],v[maxn],ans,dp[maxn];
struct node{
	int v,w,id;
	double b;
}g[maxn];
bool cmp(node x,node y)
{
	if(x.b-y.b<eps && y.b-x.b<eps){
		if(x.w==y.w) return x.id<y.id;
		return x.w>y.w;
	}
	return x.b>y.b;
}
bool check()
{
	//right
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j-v[i]>=0;j--)
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	}
	//X
	for(int i=1;i<=n;i++)
	{
		g[i].b=(double)(w[i])/(double)(v[i]);
		g[i].v=v[i];g[i].w=w[i];g[i].id=i;
	}
	sort(g+1,g+n+1,cmp);
	int tmp=m,tans=0;
	for(int i=1;i<=n;i++)
	{
		if(tmp-g[i].v<0) continue;
		tmp-=g[i].v,tans+=g[i].w;
	}
	int tdp=dp[m];
	memset(dp,0,sizeof(dp));
	if(tans==tdp) return 1;
	else return 0;
}
void dfs(int now)
{
	if(now>n){if(check()) ans++;return;}
	v[now]=1;
	dfs(now+1);
	v[now]=2;
	dfs(now+1);
	v[now]=0;
	return;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if(c<=5)
	{
		cin>>c>>t;
		while(t--)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++)
				cin>>w[i];
			dfs(1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
