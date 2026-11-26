#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=1e5+5,MOD=998244353;
int i,j,n,a[N],c,T,m,dp[N],ans,sta;
struct candy
{
	int yu,w;
	double bi;
}can[N];
bool cmp(candy a,candy b)
{
	if(a.bi!=b.bi)return a.bi>b.bi;
	return a.yu>b.yu;
}
int qpow(int a,int n,int mod)
{
	int ans=1;
	while(n>1)
	{
		if(n%2==1)ans*=a,ans%=mod,n--;
		if(n%2==0)ans*=ans,ans%=mod,n/=2;
	}
	return ans;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		int fl=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=a[i-1])fl=1;
		}
		if(n<=10)
		{
			int ans=0;
			for(int k=0;k<=(1<<n)-1;k++)
			{
				int sum=0,p=k,lef=m,rans=0;
				for(i=1;i<=n;i++)can[i].yu=a[i],can[i].w=p%2+1,p/=2,can[i].bi=(double)can[i].yu/can[i].w;
				sort(can+1,can+n+1,cmp);
				for(i=1;i<=n;i++)
				{
					if(lef-can[i].w<0)continue;
					sum+=can[i].yu,lef-=can[i].w;
					if(lef==0)break;
				}
				for(i=1;i<=m;i++)dp[i]=0;
				for(i=1;i<=n;i++)
				{
					for(j=m;j>=can[i].w;j--)dp[j]=max(dp[j],dp[j-can[i].w]+can[i].yu);
				}
				for(i=1;i<=m;i++)rans=max(rans,dp[m]);
				if(rans==sum)ans++;
				//cout<<rans<<' '<<sum<<endl;
			}
			cout<<ans<<endl;
		}
		if(fl==0)cout<<qpow(2,n,MOD)<<endl;
		if(m==2)
		{
			ans=qpow(2,n,MOD);
			sort(a+1,a+n+1);
			sta=a[n];
			for(i=1;i<=n;i++)
			{
				if(a[i]*2>sta)
				{
					for(j=1;j<i;j++)if(a[j]+a[i]<sta)ans-=qpow(2,j-1,MOD);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
