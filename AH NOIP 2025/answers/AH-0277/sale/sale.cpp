#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
long long a[5005],s=1;
const long long mod=998244353;
int main()
{
freopen("sale.in","r",stdin);
freopen("sale.out","w",stdout);
cin>>c>>t;
for(int ii=1;ii<=t;ii++)
{
	cin>>n>>m;
	long long tt=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c==18)for(int i=1;i<=n;i++)s*=2,s%=mod;
	else if(c==7||c==8||c==9||c==14||c==15)
	{
		sort(a+1,a+1+n);
		long long tt=1;
		for(int i=1;i<=n;i++)s*=2,s%=mod;
		if(a[n]*1.0/2>=a[n-1]+a[n-2])tt=0;
		else if(a[n]>a[n-1]+a[n-2]&&a[n]/2<a[n-1])
			for(int i=1;i<=n-2;i++)tt*=2,tt%=mod;
	}
	else if(c==16)
	{
		sort(a+1,a+1+n);
		long long tt=1;
		for(int i=1;i<=n;i++)s*=2,s%=mod;
		if(a[n]*1.0/2>=a[n-1]+a[n-2])tt=0;
		else if(a[n]>a[n-1]+a[n-2]&&a[n]/2<a[n-1])
			for(int i=1;i<=n-2;i++)tt*=2,tt%=mod;
	}
	else if(c==17)
	{
		sort(a+1,a+1+n);
		long long tt=1;
		for(int i=1;i<=n;i++)s*=2,s%=mod;
		if(a[n]*1.0/2>=a[n-1]+a[n-2])tt=0;
		else if(a[n]>a[n-1]+a[n-2]&&a[n]/2<a[n-1])
			for(int i=1;i<=n-2;i++)tt*=2,tt%=mod;
	}
	else
	{
		sort(a+1,a+1+n);
		long long tt=1;
		for(int i=1;i<=n;i++)s*=2,s%=mod;
		if(a[n]*1.0/2>=a[n-1]+a[n-2])tt=0;
		else if(a[n]>a[n-1]+a[n-2]&&a[n]/2<a[n-1])
			for(int i=1;i<=n-2;i++)tt*=2,tt%=mod;
	}
	cout<<(s-tt)%mod<<endl;
}
return 0;
}
