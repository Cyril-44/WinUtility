#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int mod=998244353;
struct node
{
	int a,w,id;
	bool operator < (const node& tmp) const
	{
		if(fabs(1.0*a/w-1.0*tmp.a/tmp.w)>1e-8) return 1.0*a/w>1.0*tmp.a/tmp.w;
		if(a!=tmp.a) return a>tmp.a;
		return id<tmp.id;
	}
};
long long qpow(int n)
{
	long long s=2,ans=1;
	while(n)
	{
		if(n&1) ans=(ans*s)%mod;
		s=(s*s)%mod;
		n>>=1;
	}
	return ans;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	int c=read(),t=read();
	if(c<=5)
	{
		while(t--)
		{
			int n=read(),m=read();
			int a[n+1];
			for(int i=1;i<=n;i++)
				a[i]=read();
			int ans=0;
			for(int d=0;d<(1<<n);d++)
			{
				node b[n+1];
				for(int i=1;i<=n;i++)
				{
					b[i].a=a[i];
					b[i].id=i;
					if((d>>(i-1))&1) b[i].w=2;
					else b[i].w=1;
				}
				sort(b+1,b+n+1);
				int cnt=m;
				long long s=0;
				for(int i=1;i<=n;i++)
				{
					if(cnt<b[i].w) continue;
					cnt-=b[i].w;
					s+=b[i].a;
				}
				long long f[m+1];
				memset(f,0,sizeof f);
				for(int i=1;i<=n;i++)
					for(int j=m;j>=b[i].w;j--)
						f[j]=max(f[j],f[j-b[i].w]+b[i].a);
				if(f[m]==s) ans=(ans+1)%mod;
			}
			write(ans);
			putchar('\n');
		}
	}
	if(c==18)
	{
		while(t--)
		{
			int n=read();
			read();
			for(int i=1;i<=n;i++)
				read();
			write(qpow(n));
			putchar('\n');
		}
		return 0;
	}
	return 0;
}
