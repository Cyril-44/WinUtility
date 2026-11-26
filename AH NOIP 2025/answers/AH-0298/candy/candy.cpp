#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10,M=1e18;
ll n,m,k,id,maxs=M+10,ans,cnt,cum,a[N],c[N];
pair<ll,ll> b[N];
ll read()
{
	ll s=0,f=1;
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
void write(ll s)
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
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read();
	m=read();
	for (int i=1; i<=n; i++)
	{
		int x,y;
		cin >> x >> y;
		b[i]=make_pair(x,y);
		a[i]=x+y;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for (int i=1; i<n; i+=2)
	{
		if (b[i].first+b[i+1].first<a[1])
		{
			m-=b[i].first;
			m-=b[i+1].first;
			id=i;
			ans+=2;
		}
		else
		{
			break;
		}
	}
	id++;
	if (m>=a[1])
	{
		ans+=(m/a[1])*2;
		m=m%a[1];
	}
	if (m==0)
	{
		write(ans);
		puts("");
		return 0;
	}
	for (int i=1; i<=id; i++)
	{
		c[i]=b[i].second;
	}
	sort(c+1,c+id+1);
	for (int i=1; i<=id; i++)
	{
		if (b[id+1].first<=c[i]&&m>=b[id+1].first)
		{
			c[++id]=b[id].second;
			m-=b[id].first;
			ans++;
			sort(c+i,c+id+1);
			for (int j=i; j<=id; j++)
			{
				if (m>=c[j])
				{
					m-=c[j];
					ans++;
				}
				else
				{
					break;
				}
			}
			write(ans);
			puts("");
			return 0;
		}
		if (m>=c[i])
		{
			m-=c[i];
			ans++;
		}
		else
		{
			write(ans);
			puts("");
			return 0;
		}
	}
	write(ans);
	puts("");
	return 0;
}
