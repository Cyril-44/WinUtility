#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10,Mod=998244353;
int a[N],n,m,w[N],ans;
ll dp[12][22],ow[1010];
pair<ll,ll> p[N];
ll read()
{
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

void write(ll x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

void dfs(int dep)
{
	if(dep>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+a[i]);
			}
		for(int i=1;i<=n;i++)
			p[i]=make_pair(a[i]*2/w[i],w[i]);
		sort(p+1,p+n+1,greater<pair<int,int> >());
		int k=m;
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!k) break;
			if(k>=p[i].second) 
			{
				k-=p[i].second;
				cnt += p[i].second*p[i].first/2;
				continue;
			}
		}
		if(cnt==dp[n][m]) ans++; 
		return;
	}
	w[dep]=1;
	dfs(dep+1);
	w[dep]=2;
	dfs(dep+1);
	
}

int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int C=read(),T=read();
	ow[0]=1;
	for(int i=1;i<=n;i++)
		ow[i]=ow[i-1]*2%Mod;
	while(T--)
	{
		n=read(),m=read();
		bool A=true;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(i!=1 and a[i]!=a[i-1]) A=false;
		} 
		
		if(A or m==2*n-1)
		{
			ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*2%Mod;
		}
		else if(n<=10) dfs(1);
		else if(m==2)
		{
			ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*2%Mod;
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n;i++)//n-ℹ-2
				for(int j=i+1;j<=n+1;j++)
				{
					int l=a[i]+a[j],r=a[i]*2;
					if(a[1]>=2*a[i]) break;
					for(int k=i-1;k>=1;k--)
						if(l<a[k] and a[k]<r) ans-=ow[n-i-2];
				}
			ans=(ans%Mod+ans)%Mod;
		}
		write(ans);
		puts("");
		ans=0;
	}
	return 0;
}
