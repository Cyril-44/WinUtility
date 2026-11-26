#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>

#define int long long
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

const int N=2e5+50,oo=1e18;

int n,m,z,a[N],b[N],c[N],tot,p,ans;

bool END;
signed main()
{
	double st_t=clock();
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	in(n);in(m);z=2e9;
	For(i,1,n)in(a[i]),in(b[i]),z=min(z,a[i]+b[i]);
	p=2e9;
	For(i,1,n)if(a[i]+b[i]==z)p=min(p,a[i]);
	For(i,1,n)if(a[i]+b[i]==z&&p==a[i]);
	else c[++tot]=a[i];
	sort(c+1,c+tot+1);
	ans=m/z*2+(m%z>=p);int ss=m;
	For(i,1,tot)
	{
		ss-=c[i];
		if(ss<0)break;
		int s=ss/z*2+(ss%z>=p)+i;
		ans=max(ans,s);
	}
	printf("%lld\n", ans);
	cerr<<-(&END-&START)*1.0/1024/1024<<" Mb"<<endl;
	cerr<<(clock()-st_t)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}