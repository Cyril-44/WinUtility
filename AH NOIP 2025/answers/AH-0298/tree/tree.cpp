#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8010;
ll T,n,ans,m,a[N];
vector<ll> e[N];
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
ll dfs(ll u)
{
	if (e[u].size()==0)
	{
		return 0;
	}
	bool pd=false;
	ll cnt=0;
	for (int i=0; i<e[u].size(); i++)
	{
		ll v=e[u][i];
		ll x=dfs(v);
		if (x==0&&pd==false)
		{
			pd=true;
			ans++;
		}
		if (x==0)
		{
			cnt++;
		}
		cnt+=x;
	}
	ans+=cnt+1;
	return cnt;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	T=read();
	while (T--)
	{
		n=read();
		m=read();
		ans=0;
		memset(a,0,sizeof a);
		for (int i=1; i<=n; i++)
		{
			e[i].clear();
		}
		for (int i=2; i<=n; i++)
		{
			ll x=read();
			e[x].push_back(i);
		}
		dfs(1);
		write(ans);
		puts("");
	}
	return 0;
}
