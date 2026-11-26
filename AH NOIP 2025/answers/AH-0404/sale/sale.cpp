#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long c,t,n,m,a[5005],ans,tmpmx,vis[5005],dp[10005];
struct fun
{
	double w;
	long long id;
}tmp[5005];
bool cmp(fun x,fun y)
{
	if (x.w!=y.w)
	{
		return x.w>y.w;
	}
	if (a[x.id]!=a[y.id])
	{
		return a[x.id]>a[y.id];
	}
	return x.id<y.id;
}
void dpp()
{
	memset(dp,0,sizeof(dp));
	tmpmx=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=vis[i];j--)
		{
			dp[j]=max(dp[j],dp[j-vis[i]]+a[i]);
			tmpmx=max(tmpmx,dp[j]);
		}
	}
	return;
}
void dfs(long long w)
{
	if (w>n)
	{
		for (int i=1;i<=n;i++)
		{
			tmp[i].w=a[i]*1.0/vis[i];
			tmp[i].id=i;
		}
		sort(tmp+1,tmp+1+n,cmp);
		long long tmpans=0,tmpm=m;
		for (int i=1;i<=n;i++)
		{
			if (vis[tmp[i].id]<=tmpm)
			{
				tmpm-=vis[tmp[i].id];
				tmpans+=a[tmp[i].id];
			}
		}
		dpp();
		if (tmpans==tmpmx)
		{
			ans++;
		}
		return;
	}
	vis[w]=1;
	dfs(w+1);
	vis[w]=2;
	dfs(w+1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=0;
		if (n<=10)
		{
			dfs(1);
			cout<<ans<<"\n";
			continue;
		}
		if (m==2*n-1)
		{
			cout<<pow(2,n)<<"\n";
			continue;
		}
	}
	return 0;
}
