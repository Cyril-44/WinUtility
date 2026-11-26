#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>

#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ULL unsigned long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Rep(i,l,r) for(int i=l;i>=r;i--)
using namespace std;

bool START;

void in(int &x)
{
	char c=getchar();int op=1;
	while(c>'9'||c<'0')op*=(c=='-'?-1:1),c=getchar();
	for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';x*=op;
}

const int N=5e4+40,oo=1e18;

int n,m,a[N],q[N],hh,tt,Q,b[N],sum[N],as[N],qx[N],qy[N];

namespace BF
{
	void solve()
	{
		For(i,1,Q)
		{
			int L=qx[i],R=qy[i];
			For(i,1,n)as[i]=-oo;
			For(len,L,R)
			{
				For(i,len,n)b[i]=sum[i]-sum[i-len];
				hh=1;tt=0;
				Rep(i,n,1)
				{
					while(hh<=tt&&q[hh]>i+len-1)hh++;
					if(i>=len)
					{
						while(hh<=tt&&b[q[tt]]<=b[i])tt--;
						q[++tt]=i;
					}
					as[i]=max(as[i],b[q[hh]]);
				}
			}ULL ans=0;
			For(i,1,n)ans^=(as[i]*i);
			printf("%llu\n", ans);
		}
	}
}

namespace BF2
{
	int f[50010][6][35],lg[N];
	int qmax(int u,int l,int r)
	{
		int k=lg[r-l+1];
		return max(f[u][k][l],f[u][k][r-(1<<k)+1]);
	}
	void solve()
	{
		For(i,1,n)lg[i]=(i==1?0:lg[i/2]+1);
		For(len,1,32)
			{
				For(i,len,n)b[i]=sum[i]-sum[i-len];
				hh=1;tt=0;
				Rep(i,n,1)
				{
					while(hh<=tt&&q[hh]>i+len-1)hh++;
					if(i>=len)
					{
						while(hh<=tt&&b[q[tt]]<=b[i])tt--;
						q[++tt]=i;
					}
					f[i][0][len]=b[q[hh]];
				}
			}
		For(u,1,n)
		For(w,1,5)For(i,1,32-(1<<w)+1)
		{
			f[u][w][i]=max(f[u][w-1][i],f[u][w-1][i+(1<<(w-1))]);
		}
		For(i,1,Q)
		{
			int L=qx[i],R=qy[i];
			ULL ans=0;
			For(u,1,n)
			{
				ans^=(u*qmax(u,L,R));
			}
			printf("%llu\n", ans);
		}
	}
}

namespace subD
{
	int pre[N],suf[N];
	void solve()
	{
		For(qq,1,Q)
		{
			int L=qx[qq],R=qy[qq];
			hh=1;tt=0;
			For(i,0,n+1)as[i]=pre[i]=suf[i]=-oo;
			For(i,1,n)
			{
				while(hh<=tt&&q[hh]<i-R)hh++;
				if(i>=L)
				{
					while(hh<=tt&&sum[q[tt]]>sum[i-L])tt--;
					q[++tt]=i-L;
					suf[i]=sum[i]-sum[q[hh]];
				}
			}
			hh=1;tt=0;
			Rep(i,n,1)
			{
				while(hh<=tt&&q[hh]>i+R-1)hh++;
				if(i+L-1<=n)
				{
					while(hh<=tt&&sum[q[tt]]<sum[i+L-1])tt--;
					q[++tt]=i+L-1;
					pre[i]=sum[q[hh]]-sum[i-1];
				}
			}
			Rep(i,n,1)suf[i]=max(suf[i],suf[i+1]);
			For(i,1,n)pre[i]=max(pre[i-1],pre[i]);
			For(i,1,n)if(i*2<=n)as[i]=pre[i];else as[i]=suf[i];
			ULL ans=0;
			For(i,1,n)ans^=(1llu*i*as[i]);
			printf("%llu\n", ans);
		}
	}
}

bool END;
signed main()
{
	double st_t=clock();
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	in(n);For(i,1,n)in(a[i]),sum[i]=sum[i-1]+a[i];
	int flg=1,zz=1;
	in(Q);For(i,1,Q)in(qx[i]),in(qy[i]),flg&=(qx[i]==qy[i]),zz&=(qx[i]*2>n);
	if(flg||(n<=3000&&Q<=50)) {BF::solve();return 0;}
	if(zz)
	{
		subD::solve();return 0;
	}
	BF2::solve();
	cerr<<-(&END-&START)*1.0/1024/1024<<" Mb"<<endl;
	cerr<<(clock()-st_t)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
//!noip@Nov29,2025:dream