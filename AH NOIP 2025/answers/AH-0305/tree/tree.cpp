#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <cstdlib>

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

const int N=8010,oo=1e9;

int n,m,fa[N],Tst;

namespace bf
{
	vector<int> G[N];
	int f[19][(1<<18)+5],a[(1<<18)+5],b[(1<<18)+5];
	void solve()
	{
		For(i,1,n)G[i].clear();
		For(i,2,n)in(fa[i]),G[fa[i]].push_back(i);
		int U=(1<<n);
		Rep(u,n,1)
		{
			For(i,0,U-1)f[u][i]=-oo;
			For(i,0,n-1)f[u][1<<i]=0;
		}
		Rep(u,n,1)
		{
			for(int v:G[u])
			{
				For(s,0,U-1)b[s]=f[v][s],a[s]=f[u][s];
				Rep(i,n-1,0) For(s,0,U-1)if(s>>i&1)
				{
					b[s^(1<<i)]=max(b[s^(1<<i)],b[s]);
				}
				For(s,0,U-1)
				{
					int tmp=f[u][s];
					for(int t=s;t!=-1;t=(!t?-1:(t-1)&s))
					{
						tmp=max(tmp,a[t]+b[s^t]);
					}
					f[u][s]=tmp;
				}
			}
			For(s,0,U-1)if(f[u][s]>=0)
			{
				int x=s;while(x&1)f[u][s]++,x>>=1;
			}
		}
		int ans=0;
		For(s,0,U-1)ans=max(ans,f[1][s]);printf("%d\n", ans);
	}
}

namespace ano
{
	vector<int> G[N];
	int a[N],tot;
	void solve()
	{
		tot=0;
		For(i,1,n)G[i].clear();
		For(i,2,n)in(fa[i]),G[fa[i]].push_back(i);
		For(i,2,n)if(fa[i]==1)a[++tot]=G[i].size();
		int t=0;For(i,1,tot)t=max(t,a[i]);
		if(t==0)
		{
			printf("%d\n",n+1);return ;
		}
		int ans=t+2;
		For(i,1,tot)if(a[i]) ans+=1+a[i]+1;else ans++;
		printf("%d\n",ans);
	}
}

bool END;
int main()
{
	double st_t=clock();
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	in(Tst);while(Tst--)
	{
		in(n);in(m);
		if(m==2&&n>13){ano::solve();continue;}
		bf::solve();
	}
	cerr<<-(&END-&START)*1.0/1024/1024<<" Mb"<<endl;
	cerr<<(clock()-st_t)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
//!noip@Nov29,2025:dream