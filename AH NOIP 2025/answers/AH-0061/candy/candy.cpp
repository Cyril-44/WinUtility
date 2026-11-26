#include<stdio.h>
#include<algorithm>
#include<string.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int n,m,x[MAXN],y[MAXN],dou=1e18+7,ans;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld %lld",x+i,y+i);
	for(int i=1;i<=n;i++)dou=min(dou,x[i]+y[i]);
	sort(x+1,x+1+n);
	ans=m/dou*2;
	for(int i=1,sum=0;i<=n;i++)
	{
		sum+=x[i];
		ans=max(ans,i+(m-sum)/dou*2);
	}
	printf("%lld",ans);
	return 0;
}
