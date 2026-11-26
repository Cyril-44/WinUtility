#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int x[10001],y[10001],z[100001];
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		z[i]=x[i]+y[i];
	}
	long long flag=2000000000;
	for(int i=1;i<=n;i++)
	{
		if(flag>z[i])
		flag=z[i];
	}
	int ans=0;
	ans+=((m/flag)*2);
	int sum=m-m/flag*flag;
	int k=0;
	int a[100001];
	int ccf=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]<=sum)
		{
			ccf++;
			a[ccf]=x[i];
		}
	}
	for(int i=1;i<=ccf;i++)
	{
		for(int j=i+1;j<=ccf;j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];a[i]=a[j];a[j]=t;
			}
		}
		if(sum-a[i]>=0)
		{
			sum-=a[i];
			k++;
		}
		else break;
	}
	ans+=k;
	cout<<ans;
	return 0;
}
