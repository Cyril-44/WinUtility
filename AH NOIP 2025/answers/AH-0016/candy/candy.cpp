#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

int n,m;
int a[100005][2];

priority_queue<int,vector<int>,greater<int> > g;

void work()
{
	n=read();
	m=read();
	int cnt=0;
	int ans=0;
	int minn=0x3f3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		a[i][0]=read();
		a[i][1]=read();
		minn=min(minn,a[i][0]+a[i][1]);
		g.push(a[i][0]);
	}
	cnt=m/minn*2;
	m%=minn;
	ans=max(ans,cnt);
	int re=0;
	while(g.size())
	{
		int u=g.top();
		g.pop();
		if(m<u)
		{
			if(cnt==0) break;
			int s=(u-m-1)/minn+1;
			if(cnt<2*s) break;
			cnt-=2*s;
			m+=s*minn;
		}
		if(m>=u)
		{
			re++;
			m-=u;
			ans=max(ans,cnt+re);
		}
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) work();
}
