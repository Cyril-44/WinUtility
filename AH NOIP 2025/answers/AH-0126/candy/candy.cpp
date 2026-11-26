#include<cstdio>
#include<algorithm>
#define N 100000
#define INF 2147483647
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,a=INF,x[N],y[N];
long long m,ans;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i^n;++i)
	{
		x[i]=read(),y[i]=read();
		a=min(a,x[i]+y[i]);
	}
	std::stable_sort(x,x+n);
	ans=(m/a)*2;
	for(int i=0;i^n;++i)
	{
		m-=x[i];
		ans=max(ans,m/a*2+i+1);
	}
	printf("%lld",ans);
	return 0;
}
