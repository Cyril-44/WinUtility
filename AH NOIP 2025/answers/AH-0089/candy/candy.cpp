#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5,MA=2*1e9+5;
LL n,m,dou=MA,sim[N],ans;
LL lmin(LL x,LL y)
{
	if(x<y)return x;
	else return y;
}
LL lmax(LL x,LL y)
{
	if(x>y)return x;
	else return y;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		dou=lmin(dou,x+y);
		sim[i]=x;
	}
	sort(sim+1,sim+n+1);
	LL tm=m;
	ans=(tm/dou)*2;
	for(int i=1;i<=n;i++)
	{
		if(tm<sim[i]||sim[i]>=dou)break;
		tm-=sim[i];
		ans=lmax(ans,i+(tm/dou)*2);
	}
/*	if(dou<=m)
	{ans=m/dou;ans*=2;
	m=m%dou;}*/
	printf("%lld",ans);
	return 0;
}
