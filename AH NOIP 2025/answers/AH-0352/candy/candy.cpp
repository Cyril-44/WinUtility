#include <bits/stdc++.h>
using namespace std;
const int mx=1e4+7;
long long n,m;
int main()                                                                                  
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int w[100005],price[100005],value[100005];
	if(n>1000)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>price[i]>>value[i];
			value[i]+=price[i];
		}
		sort(price+1,price+n+1);
		sort(value+1,value+n+1);
		long long ans=0;
		price[0]=0;
		long long sum=0;
		for (int i=0;i<=n;i++)
		{
			sum+=price[i];
			ans=max(i+2*((m-sum)*1ll/value[1]),ans);
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>price[i]>>value[i];
		value[i]+=price[i];
		for (int j=m;j>=1;j--)
		{
			if(w[j]>0&&(price[i]+j)<=m)
			{
				w[j+price[i]]=max(w[j]+1,w[j+price[i]]);
			}
		}
		w[price[i]]=max(w[price[i]],1);
	} 
	for (int i=1;i<=n;i++)
	{
		w[value[i]]=max(w[value[i]],2);
		for (int j=1;j<=m;j++)
		{
			if(w[j]>0&&(value[i]+j)<=m)
			{
				w[value[i]+j]=max(w[j]+2,w[value[i]+j]);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		ans=max(ans,w[i]);
	}
	cout<<ans<<endl;
	return 0;
}
