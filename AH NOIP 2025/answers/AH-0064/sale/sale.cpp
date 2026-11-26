#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10,mod=998244353;
struct Node{
	int id;
	double b;
};
int zh[N];
int a[N];
int w[N];
Node e[N];
int n;
int m;
int ans;
bool cmp(Node x,Node y)
{
	if(x.b==y.b)
		return a[x.id]>a[y.id];
	return x.b>y.b;
}
int dp[4*N];
void check(int sum,int cnt1)
{
	for(int i=1;i<=n;i++)
	{
		e[i].b=a[i]*1.0/w[i];
		e[i].id=i;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(sum>=w[e[i].id])
		{
			sum=sum-w[e[i].id];
			cnt1=cnt1+a[e[i].id];
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(j>=w[i])
				dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
	if(dp[m]==cnt1) ans++;
}
void dfs(int step)
{
	if(step>n)
	{
		check(m,0);
		return;
	}
	for(int i=1;i<=2;i++)
	{
		w[step]=i;
		step++;
		dfs(step);
		step--;
	}
}
bool cmp2(int x,int y)
{
	return x>y;
}
void init()
{
	zh[0]=1;
	for(int i=1;i<=5000;i++)
		zh[i]=zh[i-1]*2%mod;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	init();
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c>=1&&c<=5)
		{
			dfs(1);
			cout<<ans<<endl;
		}
		else if(c==18)
		{
			ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*2%mod;
			cout<<ans<<endl;
		}
		else if((c>=7&&c<=9)||(c>=14&&c<=15))
		{
			sort(a+1,a+1+n,cmp2);
			ans=zh[n];
			int k=a[1];
			for(int i=2;i<=n;i++)
			{
				if(a[i]>(k/2))
				{
					ans=(ans+mod-1)%mod;
					for(int j=i+1;j<=n;j++)
					{
						if(a[i]+a[j]<k)
							ans=(ans+mod-zh[n-j])%mod;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(c==16)
		{
			cout<<zh[n]<<endl;
		}
		else if(c==17)
		{
			sort(a+1,a+1+n);
			double kk=a[2];
			if(a[1]>kk*1.0/2)
				ans=(zh[n]+mod-1)%mod;
			else ans=zh[n];
			cout<<ans<<endl;
		}
		else
		{
			cout<<zh[n]<<endl;
		}
	}
	return 0;
}
