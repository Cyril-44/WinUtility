#include<bits/stdc++.h>
using namespace std;
double c,t,a[5010],dp[5010][2510];
long long ans,mx,sum,p[5010],n,m,p1[5010],a1[5010];
void fdp()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j-p1[i]>=0) dp[i][j]=max(dp[i-1][j],dp[i-1][j-p1[i]]+a1[i]);
			else dp[i][j]=dp[i-1][j];
		} 
	}
	mx=dp[n][m];
}
void dfs(int k)
{
	if(k==n+1)
	{
		
		for(int i=1;i<=n;i++) p1[i]=p[i];
		for(int i=1;i<=n;i++) a1[i]=a[i];
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a1[i]/p1[i]<a1[j]/p1[j])
				{
					swap(a1[i],a1[j]);
				    swap(p1[i],p1[j]);
				}
				else if(a1[i]/p1[i]==a1[j]/p1[j]&&a1[i]<a1[j])
				{
					swap(a1[i],a1[j]);
					swap(p1[i],p1[j]);
				}
			}
		fdp();
		long long sum=0,km=m;
		for(int i=1;i<=n;i++)
		{
			if(km-p1[i]<0) continue;
			km-=p1[i]; 
			sum+=a1[i];
		} 
		cout<<mx<<" "<<sum<<endl;
		if(sum==mx)
		{
			ans++;
			ans%=998244353;
		} 
		return;
	}
	p[k]=1;
	dfs(k+1);
	p[k]=2;
	dfs(k+1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
