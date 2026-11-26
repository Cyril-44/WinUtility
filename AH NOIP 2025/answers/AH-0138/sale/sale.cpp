#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,flag;
double a[5010];
long long cnt[5010],benshen[5010],t[5010];
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=a[i-1]&&i>1)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<2<<endl;
		}
		else
		{
			sort(a+1,a+1+n);
			cnt[1]=2;
			for(int i=2;i<=n;i++)
			{
				if(a[i]/2>a[i-1])
				{
					cnt[i]=cnt[i-1]*2%998244353;
					benshen[i]=2;
				}
				else
				{
					benshen[i]=1;
					if(a[i]/2<a[i-1])
					{
						if(benshen[i-1]==2)
						{
							cnt[i]=cnt[i-1]/2*3%998244353;
							t[i]=3;
						}
						if(benshen[i-1]==1)
						{
							t[i]=t[i-1]+1;
							cnt[i]=cnt[i-1]/t[i-1]*t[i]%998244353;
						}
					}
				}
			}
			cout<<cnt[n]<<endl;
			for(int i=1;i<=n;i++)
			{
				cnt[i]=0;
				benshen[i]=0;
			}
			flag=0;
		}
	}
}
