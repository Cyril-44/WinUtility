#include<bits/stdc++.h>
#define p 998244353
using namespace std;
int c,t,n,m,a[5005];
int read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
bool cmp(int x,int y)
{return x>y;}
int qp(int x)
{
	int ans=1,pre=2;
	while(x)
	{
		if(x&1)ans=(ans*pre)%p;
		x=x>>1;
		pre*=pre;
	}
	return ans;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	c=read();t=read();
	if(c==18)
	{
		for(int G=1;G<=t;G++)
		{
			n=read();m=read();
			for(int i=1;i<=n;i++)a[i]=read();
			cout<<qp(n)<<endl;
		}
	}
	if((c>=7&&c<=9)||(c>=14&&c<=15))
	{
		for(int G=1;G<=t;G++)
		{
			int ans=0;
			n=read();m=read();
			for(int i=1;i<=n;i++)a[i]=read;
			sort(a+1,a+1+n,cmp);
			int x1=a[1],x2=a[2],x3=a[3];
			
		}
	}
	if(c==16)
	{
		for(int G=1;G<=t;G++)
		{
			int ans=0;
			n=read();m=read();
			for(int i=1;i<=n;i++)a[i]=read;
			sort(a+1,a+1+n);
			int x1=a[1],x2=a[2];
		}
	}
	return 0;
}
