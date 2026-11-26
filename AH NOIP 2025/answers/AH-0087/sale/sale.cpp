#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0; re char c;
	while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48);
	while((c=getchar())>'-');
	return x;
}
inline void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10|48);
}
namespace Case18
{
	int a[1003],fact[1003],inv[1003];
	inline void init()
	{
		fact[0]=1;
		for(re int i=1;i<1001;++i)
			fact[i]=fact[i-1]*i;
	}
	int C(int n,int m)
	{
		return 1;
	}
	inline void solve()
	{
		int t; cin>>t;
		init();
		while(t--)
		{
			int n=read();
		}
	}
}
namespace Case5
{
	typedef long long LL;
	const int Mod=998244353;
	int a[45];
	struct Node
	{
		int w,id;
		bool operator < (const Node& x) const {
			if(a[id]*x.w!=a[x.id]*w) return a[id]*x.w>a[x.id]*w;
			if(a[id]!=a[x.id]) return a[id]>a[x.id];
			return id<x.id;
		}
	}b[45];
	inline void solve()
	{
		int t; cin>>t;
		while(t--)
		{
			int n=read(),m=read();
			LL maxv=-1; int ans;
			for(re int i=0;i<n;a[++i]=read());
			LL tot=1<<n-1;
			for(re LL i=0;i<=tot;++i)
			{
				for(re int j=0;j<n;b[j].id=j,++j)
					if((i>>j)&1) b[j].w=2;
					else b[j].w=1;
				sort(b,b+n);
				LL sum=0;
				int mon=m;
				for(re int i=0;i<n;++i)
					if(mon>=b[i].w) sum+=a[b[i].id],mon-=b[i].w;
				if(sum>maxv) maxv=sum,ans=1;
				else if(sum==maxv) if(++ans==Mod) ans=0;
			}
			write(maxv),putchar(10);
		}
	}
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	short c; cin>>c;
	if(c==18) Case18::solve();
	if(!c || c<=6) Case5::solve();
	return 0;
}
