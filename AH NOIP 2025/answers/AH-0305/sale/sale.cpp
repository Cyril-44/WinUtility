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
const int N=5010,P=998244353;

int n,m,Cid,Tst,a[N],b[N],c[N],d[N],ans;

struct node{int a,w,v;}p[N];
bool operator<(node a,node b){if(a.v!=b.v)return a.v>b.v;return a.a>b.a;}
int pw[N];
void Work()
{
	in(n);in(m);
	For(i,1,n)in(a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int ans=1;
	For(i,1,n)ans=ans*2%P;
	if(a[1]==a[n])
	{
		printf("%lld\n",ans);return ;
	}
	pw[0]=1;
	For(i,1,n)pw[i]=pw[i-1]*2%P;
	if(m==2)
	{
		int ts=0;
		For(x,1,n)For(y,x+1,n)
		{
			int z=1;while(z==x||z==y)z++;
			if(a[x]*2>a[z]&&a[x]+a[y]<a[z])
			{
				ts+=pw[n-max(y,z)];
			}
		}
		For(x,1,n)
		{
			int y=(x==1?2:1);
			if(a[x]*2>a[y]&&a[x]<a[y])ts++;
		}
		ans=(ans+P-ts%P)%P;printf("%lld\n",ans);return;
	}
	if(m==n*2-1)
	{
		printf("%lld\n",pw[n]);return ;
	}
	For(S,0,(1<<n)-1)
	{
		For(i,1,n)d[i]=(S>>(i-1)&1)+1;
		int n1=0,n2=0;
		For(i,1,n)if(d[i]==1)b[++n1]=a[i];else c[++n2]=a[i];
		For(i,1,n)p[i]={a[i],d[i],a[i]*2/d[i]};
		sort(p+1,p+n+1);
		int nw=m,ns=0,kn=0,zz=0;
		For(i,1,n)
		{
			zz+=p[i].w;
			if(nw>=p[i].w)
			{
				nw-=p[i].w;ns+=p[i].a;
			}
		}
		if(m>=zz)continue;
		For(i,1,n)c[i]+=c[i-1],b[i]+=b[i-1];
		For(i,0,n2)
		{
			if(i*2>m)break;
			int k=min(n1,m-i*2);
			kn=max(kn,c[i]+b[k]);
		}
		if(kn==ns)continue;
		// printf("S=%lld,kn=%lld,ns=%lld\n",S,kn,ns);
		// For(i,1,n)printf("%lld ", d[i]);puts("");
		ans--;
		// For(i,1,n)printf("%lld ", p[i].w);puts("");
	}
	ans=(ans%P+P)%P;printf("%lld\n", ans);
}

bool END;
signed main()
{
	double st_t=clock();
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	in(Cid);in(Tst);
	while(Tst--)Work();
	cerr<<-(&END-&START)*1.0/1024/1024<<" Mb"<<endl;
	cerr<<(clock()-st_t)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
//!noip@Nov29,2025:dream