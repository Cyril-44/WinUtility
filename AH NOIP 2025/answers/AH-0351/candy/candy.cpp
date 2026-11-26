#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100010][2]={0};
int dp[10010]={0};
int t[10010]={0};
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int test=3;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		if(a[i][0]>a[i][1])test=min(test,2ll);
		else if(a[i][0]<a[i][1])test=1;
		a[i][1]+=a[i][0];
	}
	if(m<=10000)
	{
		int maxn=0;
		t[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m-a[i][1];j++)
			{
				if(t[j])
				{
					dp[j+a[i][1]]=max(dp[j+a[i][1]],dp[j]+2);
					t[j+a[i][1]]=1;
					maxn=max(maxn,dp[j+a[i][1]]);
				}
			}
			for(int j=m-a[i][0];j>=0;j--)
			{
				if(t[j])
				{
					dp[j+a[i][0]]=max(dp[j+a[i][0]],dp[j]+1);
					t[j+a[i][0]]=1;
					maxn=max(maxn,dp[j+a[i][0]]);
				}
			}
		}
		cout<<maxn<<endl;
	}
	else if(test==3)
	{
		int mina=1e9;
		for(int i=1;i<=n;i++)
		{
			mina=min(mina,a[i][0]);
		}
		cout<<m/mina;
	}
	else if(test==2)
	{
		int mina=1e9,mina2=2e9;
		for(int i=1;i<=n;i++)
		{
			mina=min(mina,a[i][0]);
			mina2=min(mina2,a[i][1]);
		}
		int x=m/mina2;
		cout<<x*2+(m-x*mina2>=mina);
	}
	return 0;
}
