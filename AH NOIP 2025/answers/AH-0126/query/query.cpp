#include<cstdio>
#define N 50001
#define INF (1LL<<60)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define sum(l,r) (sum[r]-sum[(l)-1])
int n,q,L,R;
long long a[N],sum[N],x;
unsigned long long ans;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=n;++i)
//		printf("%lld ",sum[i]);
//	printf("\n");
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&L,&R);
		ans=0;
		for(int i=1;i<=n;++i)
		{
			x=-INF;
			for(int len=L;len<=R;++len)
				for(int j=max(1,i-len+1);j<=min(i,n-len+1);++j)
					x=max(x,sum(j,j+len-1));
			ans^=x*i;
//			printf("%lld ",x);
		}
		printf("%llu\n",ans);
	}
	return 0;
}
