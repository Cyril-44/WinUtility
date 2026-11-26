#include<bits/stdc++.h>
using namespace std;
int n,a[100001][2],ansm[1000001],ans;
bool wh[100001];
long long m;
void dfs(int cnt,long long mon)
{
	if(cnt<ansm[mon])return ;
	ansm[m]=cnt;
	ans=max(ans,ansm[m]);
	if(mon==0)return ;
	for(int i=1;i<=n;i++)
	{
		if(wh[i]==1)
		{
			if(mon>=a[i][1])
			{
				wh[i]=0;
				dfs(cnt+1,mon-a[i][1]);
				wh[i]=1;
			}
		}
		else
		{
			if(mon>=a[i][0])
			{
				wh[i]=1;
				dfs(cnt+1,mon-a[i][0]);
				wh[i]=0;
			}
		}
	}
	return ;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	bool flag=1;
	int minn=1000000000;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i][1],&a[i][0]);
		if(a[i][1]!=a[i][0])flag=0;
		minn=min(minn,a[i][1]);
		wh[i]=1;
	}
	if(flag)
	{
		if(m>=minn)
		{
			ans=floor(m/minn);
			printf("%d",ans);
		}
	}
	else
	{
		dfs(0,m);
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
