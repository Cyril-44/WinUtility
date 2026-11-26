#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[1145],plan[1145],dp[1145],ans;
struct xy
{
	int x,y;//price and (1 or 2)
}b[1145];
bool operator <(xy x,xy y)
{
	if(x.x*2/x.y!=y.x*2/y.y)return 2/x.y*x.x>2/y.y*y.x;
	else return x.y>y.y;
}
void check()
{
	for(int i=1;i<=n;++i)b[i].x=a[i],b[i].y=plan[i];
	for(int i=0;i<=m;++i)dp[i]=0;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=plan[i];--j)
		{
			dp[j]=max(dp[j],dp[j-plan[i]]+a[i]);
		}
	}
	ans1=dp[m];
	sort(b+1,b+1+n);
	int rm=m;
	for(int i=1;i<=n;++i)
	{
		//printf("%lld %lld\n",b[i].x,b[i].y);
		if(rm==0)break;
		if(b[i].y<=rm)
		{
			ans2+=b[i].x;
			rm-=b[i].y;
		}
	}
	if(ans1==ans2)
	{
		/*for(int i=1;i<=n;++i)
		{
			printf("%lld ",plan[i]);
		}
		puts("");
		printf("success:%lld %lld\n",ans1,ans2);*/
		ans++;
	}
	else
	{
		;
		/*for(int i=1;i<=n;++i)
		{
			printf("%lld ",plan[i]);
		}
		puts("");
		printf("fail:%lld %lld\n",ans1,ans2);*/
	}
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i&(1<<(j-1)))plan[j]=2;
				else plan[j]=1;
			}
			check();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
