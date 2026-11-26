#include<bits/stdc++.h>
using namespace std;
//so you say,at +15min,i ac the A?
//and you say,the competition ended?
//****ccf
#define int long long
int n,m,a[114514],b[114514],minn=LONG_LONG_MAX,ans,sum;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		b[i]=b[i]+a[i];
		minn=min(minn,b[i]);
	}
	sort(a+1,a+1+n);
	ans=(m/minn)*2;
	for(int i=1;i<=n;++i)
	{
		sum+=a[i];
		ans=max(ans,i+((m-sum)/minn)*2);
	}
	printf("%lld\n",ans);
	return 0;
}
