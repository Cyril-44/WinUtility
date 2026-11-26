#include<bits/stdc++.h>
using namespace std;
const int Maxn=5005;
long long ans=0;
struct candy
{
	long long yj, xj, xjb, pos;
}a[Maxn];
int n, m;
bool cmp(candy x, candy y)
{
	if(x.xjb!=y.xjb) return x.xjb>y.xjb; 
	if(x.yj!=y.yj) return x.yj>y.yj; 
	if(x.pos!=y.pos) return x.pos<y.pos; 
	return false;
}
bool cmpb(candy x, candy y)
{
	return x.pos<y.pos; 
}
bool pd()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i].xj;
		a[i].xjb=a[i].yj;
		if(a[i].xj==1) a[i].xjb*=2; 
	}
	sort(a+1,a+n+1,cmp);
	int nm=m;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].xj<=nm)
		{
			nm-=a[i].xj;
			sum+=a[i].yj;
		}
	}
	vector<long long> dp(cnt+5);
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i].xj;
		for(int j=min(m,cnt);j>=a[i].xj;j--)
		{
			dp[j]=max(dp[j],dp[j-a[i].xj]+a[i].yj);
		}
	}
	sort(a+1,a+n+1,cmpb);
	for(int i=1;i<=m;i++)
	{
		if(dp[i]>sum)
		{
			return false;
		}
	}
	return true;
}
void dfs(int step)
{ 
	if(step>n)
	{
		if(pd()) ans++;
		ans%=998244353;
		return;
	}
	a[step].xj=1;
	dfs(step+1);
	a[step].xj=2;
	dfs(step+1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c, t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].yj);
			a[i].pos=i;
		}
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
3 2
1 3 5
*/
