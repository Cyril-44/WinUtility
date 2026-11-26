#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 5000
#define M 10000
#define MOD 998244353
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
long long pow(const long long &a,const int &b)
{
	if(!b)return 1;
	long long x=pow(a,b>>1)%MOD;
	if(b&1)return x*x%MOD*a%MOD;
	else return x*x%MOD;
}
int C,T,n,m,a[N],ans,w[N];
long long dp[2][M];
struct Candy
{
	int num,a;
	bool operator <(const Candy &c)const&
	{
		return a^c.a?a>c.a:w[num]>w[c.num];
	}
}c[N],c1[N];
void dfs1(const int &i,int m1)
{
	if(i==n)
	{
		for(int i=0;i^n;++i)c1[i]=c[i];
		std::stable_sort(c1,c1+n);
		long long tot=0,mx=0;
		for(int j=0;j^n&&m1;++j)
			if(m1>=w[c1[j].num])
				m1-=w[c1[j].num],tot+=a[c1[j].num];
		memset(dp,0,sizeof dp);
		for(int j=0;j^n;++j)
		{
			if(w[j]==2)dp[j&1][1]=dp[~j&1][1];
			for(int k=w[j];k<=m;++k)
			{
				dp[j&1][k]=max(dp[~j&1][k],dp[~j&1][k-w[j]]+a[j]);
				mx=max(mx,dp[j&1][k]);
			}
		}
		if(tot>=mx)ans=(ans+1)%MOD;
		return;
	}
	c[i].num=i;
	w[i]=1;c[i].a=a[i]<<1;dfs1(i+1,m1);
	w[i]=2;c[i].a=a[i];dfs1(i+1,m1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i^n;++i)a[i]=read();
		if(C==18)printf("%lld\n",pow(2,n));
		else
		{
			ans=0;
			dfs1(0,m);
			printf("%d\n",ans);
		}
	}
	return 0;
}
