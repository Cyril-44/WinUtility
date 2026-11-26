#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010,M=998244353;
int n,m,c,t,a[N];
ll ans,cnt;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int s)
{
	if (s<0)
	{
		s=-s;
		putchar('-');
	}
	if (s>9)
	{
		write(s/10);
	}
	putchar(s%10+'0');
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	c=read();
	t=read();
	while (t--)
	{
		n=read();
		m=read();
		bool pd=true;
		memset(a,0,sizeof a);
		a[1]=read();
		for (int i=2; i<=n; i++)
		{
			a[i]=read();
			if (a[i]!=a[i-1])
			{
				pd=false;
			}
		}
		if (pd)
		{
			ans=1;
			for (int i=1; i<=n; i++)
			{
				ans=ans*2%M;
			}
			write(ans);
			puts("");
		}
		if (m==2)
		{
			ans=1;
			sort(a+1,a+n+1);
			for (int i=1; i<=n; i++)
			{
				ans*=2;
				ans%=M;
			}
			double x=a[n]/2;
			cnt=1;
			for (int i=1; i<=n; i++)
			{
				if (a[i]>x)
				{
					for (int j=1; j<i; j++)
					{
						cnt*=2;
						cnt%=M;
					}
					break;
				}
			}
			write((ans+cnt)%M);
			puts("");
		}
	}
	return 0;
}
