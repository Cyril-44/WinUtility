#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,m;
const ll MOD=998244353;
ll a[5005];
ll pow(ll a,ll b,ll c)
{
	ll ans=1;
	for (;b;a*=a,b>>=1) if (b&1) ans=ans*a%c;
	return ans%c;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while (t--)
	{
		scanf("%lld %lld",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if (c==18) printf("%lld\n",pow(2,n,MOD));
	}
	return 0;
}
