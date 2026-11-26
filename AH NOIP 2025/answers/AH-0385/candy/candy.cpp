#include<bits/stdc++.h>
using namespace std;
long long b[100010];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,x,y,mn=2100000000;
	long long m,ans=0,sum=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		mn=min(mn,x+y),b[i]=x;
	}
	sort(b+1,b+1+n);
	for(int i=0;i<=n;i++)
	{
		sum+=b[i];
		if(sum>m)break;
		ans=max(ans,i+(m-sum)/mn*2);
	}
	printf("%lld",ans);
	return 0;
}
