#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long a[N];
long long w[N];
long long n,k;
long long ans=0;
struct candy
{
	long long xingjiabi;
	bool dotxjb;
	long long yuanjia;
	long long bianhao;
	long long cu;
}c[N];
long long maxn=0;
long long dp(long long f,long long lk,long long sumw)
{
	if(f>n)
		return sumw;
	if(lk-w[f]>=0)
		return max(dp(f+1,lk-w[f],sumw+a[f]),dp(f+1,lk,sumw));
	else
		return dp(f+1,lk,sumw);
}
bool cmp(candy x,candy y)
{
	if(x.xingjiabi!=y.xingjiabi)
		return x.xingjiabi>y.xingjiabi;
	else
	{
		if(x.dotxjb!=y.dotxjb)
			return x.dotxjb>y.dotxjb;
		else
		{
			if(x.yuanjia!=y.yuanjia)
				return x.yuanjia>y.yuanjia;
			else
				return x.bianhao<y.bianhao;
		}
	}
}
void dfs(int f)
{
	if(f>n)
	{
		long long maxn=dp(1,k,0);
		
		for(int i=1;i<=n;i++)
		{
			c[i].bianhao=i;
			c[i].yuanjia=a[i];
			c[i].xingjiabi=a[i]/w[i];
			c[i].dotxjb=a[i]%w[i];
			c[i].cu=w[i];
		}
		sort(c+1,c+n+1,cmp);
		long long sum=0;
		long long sumy=0;
		for(int i=1;i<=n;i++)
		{
			if(sum+c[i].cu<=k)
			{
				sum+=c[i].cu;
				sumy+=c[i].yuanjia;
			}
		}
		//for(int i=1;i<=n;i++)
		//	cout<<w[i]<<' ';
		//cout<<endl;
		//cout<<sumy<<' '<<maxn<<endl;
		if(sumy==maxn) ans++;
		return ;
	}
	w[f]=1;
	dfs(f+1);
	w[f]=2;	
	dfs(f+1);
}
long long quickpower(int base,int p)
{
	long long res=1;
	while(p)
	{
		if(p%base==1)
			res=(base*res)%998244353;
		p>>=1;
		base=(base*base)%998244353;
	}
	return res;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	dor(int j=1;j<=t;j++)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		bool b=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
				b=1;
		}
		if(b==0)
		{
			cout<<quickpower(2,n)<<endl;
			return 0;
		}
		dfs(1);	
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			w[i]=0;
			c[i].bianhao=0;
			c[i].cu=0;
			c[i].dotxjb=0;
			c[i].xingjiabi=0;
			c[i].yuanjia=0;
			ans=0;
			maxn=0;
		}
	}
	return 0;
}
