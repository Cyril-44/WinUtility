#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
pair<int,int> tmp[100];
int a[5010],n,m;
long long f[100];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.first*y.second!=y.first*x.second)return x.first*y.second>y.first*x.second;
	return x.first>y.first;
}
long long qpow(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int sch(int num)
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<num)l=mid+1;
		else r=mid;
	}
	return l;
}
int bag(int st)
{
	memset(f,0,sizeof f);
	for(int i=0;i<n;i++)
	{
		if((st>>i)&1)
			for(int j=m;j>=2;j--)f[j]=max(f[j],f[j-2]+a[i]);
		else
			for(int j=m;j>=1;j--)f[j]=max(f[j],f[j-1]+a[i]);
	}
	return f[m];
}
int tx(int st)
{
	for(int i=0;i<n;i++)tmp[i].first=a[i],tmp[i].second=((st>>i)&1)+1;
	sort(tmp,tmp+n,cmp);
	int t=m;
	long long res=0;
	for(int i=0;i<n;i++)
		if(t>=tmp[i].second)t-=tmp[i].second,res+=tmp[i].first;
	return res;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	if(c<=5)
		while(T--)
		{
			int ans=0;
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;i++)
				scanf("%d",a+i);
			for(int i=0;i<(1<<n);i++)
				if(bag(i)==tx(i))ans++;
			printf("%d\n",ans);
		}
	if(c==7||c==8||c==9||c==14||c==15)
		while(T--)
		{
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;i++)scanf("%d",a+i);
			sort(a,a+n);
			long long ans=qpow(2,n);
			for(int i=0;i<n-1;i++)
				if(a[i]*2>a[n-1])
					ans=((ans-qpow(2,sch(a[n-1]-a[i])))%mod+mod)%mod;
			printf("%lld\n",ans);
		}
	if(c==16||c==18)
		while(T--)
		{
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;i++)scanf("%d",a+i);
			printf("%lld\n",qpow(2,n));
		}
	if(c==17)
		while(T--)
		{
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;i++)scanf("%d",a+i);
			sort(a,a+n);
			if(a[0]<a[1]&&a[0]*2>a[1])printf("%lld\n",qpow(2,n)-1);
			else printf("%lld\n",qpow(2,n));
		}
	return 0;
}
