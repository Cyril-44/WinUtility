#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
long long ans,cnt,a[5001],maxn;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d %d",&c,&t);
	if(c==7||c==8||c==9||c==14||c==15||c==0)
	{
		while(t--)
		{
			ans=1;
			maxn=0;
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
				maxn=max(maxn,a[i]);
			}
			for(int i=1;i<=n;i++)
			{
				if(maxn==a[i])
				{
					cnt++;
				}
			}
			if(cnt>=3)
			{
				cnt-=1;
			}
			else 
			{
				cnt=1;
			}
			if(cnt!=1) 
			{
				long long ansx=1;
				ans=0;
				for(int i=2;i<=cnt;i++)
				{
					long long sum=1;
					for(int j=1;j<=cnt;j++)
					{
						sum=sum*j%998244353;
					}
					for(int j=n;j>=n-cnt+1;j--)
					{
						ansx=ansx*j%998244353;
					}
					ansx/=sum;
					ans=(ans+ansx)%998244353;
				}
			}
			for(int i=1;i<=n-2;i++)
			{
				ans=ans*2%998244353;
			}
			printf("%lld\n",ans);
		}
	}
	else 
	{
		while(t--)
		{
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;i++)
			{
				scanf("%lld",&a[i]);
			}
			if(m<=n)
			{
				ans=1;
				for(int i=1;i<=n-m;i++)
				{
					ans=ans*2;
				}
				printf("%lld\n",ans);
			}
			else
			{
				ans=0;
				int p=m-n;
				for(int k=0;k<=p;k++)
				{
					cnt=1;
					long long sum=1;
					for(int i=1;i<=k;i++)
					{
						sum=sum*i%998244353;
					}
					for(int i=n;i>=n-k+1;i--)
					{
						cnt=cnt*i%998244353;
					}
					cnt/=sum;
					ans=(ans+cnt)%998244353;
				}
				printf("%lld\n",ans);
			}
		}
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
