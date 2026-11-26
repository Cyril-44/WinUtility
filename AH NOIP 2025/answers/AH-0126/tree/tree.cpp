#include<cstdio>
#include<cstring>
#define N 8001
#define INF 2147483647
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
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
int T,n,m,ans,a[N],s[N],d[N],x;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		memset(s,0,sizeof s);
		for(int i=2;i<=n;++i)
		{
			a[i]=read();
			++s[a[i]];
			d[i]=d[a[i]]+1;
		}
//		if(m<=2)
//		{
			x=0;
			for(int i=2;i<=n;++i)
			{
				if(s[i])ans+=2,x=max(x,s[i]);
				else ++ans;
			}
			ans+=x+2;
//		}
		printf("%d\n",ans);
	}
	return 0;
}
