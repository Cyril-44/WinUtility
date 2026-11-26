#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,q;
long long sum[50010];
long long check(int x,int L,int R)
{
	long long sum1=-1e18;
	for(int i=L;i<=R;i++)
	{
		//cout<<"x="<<x<<endl;
		for(int j=max(x-i+1,1);j<=x;j++)
		{
			int l1=j,r1=min(n,j+i-1);
			if(r1-l1+1>R||r1-l1+1<L)continue;
			//cout<<l1<<" "<<r1<<endl;	
		//	cout<<"sum1="<<sum1<<" sum="<<sum[r1]-sum[l1-1]<<endl;
			sum1=max(sum1,sum[r1]-sum[l1-1]);
		}
	}
	//cout<<"x="<<x<<" sum1="<<sum1<<endl;
	return sum1;
}
long long a[50010];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	long long sum3=1;
	for(int i=1;i<=62;i++) sum3*=2;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();		
		sum[i]=sum[i-1]+a[i];

	}
	q=read();
	while(q--)
	{
		int L,R;
		L=read(),R=read();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=ans^(i*1LL*check(i,L,R));
		}
		printf("%lld\n",ans);
	}

	return 0;
}
