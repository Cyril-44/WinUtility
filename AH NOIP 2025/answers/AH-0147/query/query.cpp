#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,L,R,temp;
unsigned long long ans;
ll a[50005];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld",&n);a[0]=0;
	for (int i=1;i<=n;i++) {scanf("%lld",&a[i]);a[i]+=a[i-1];}
	scanf("%lld",&q);
	while (q--)
	{
		ans=0;
		scanf("%lld %lld",&L,&R);
		for (ll i=1;i<=n;i++)
		{
			temp=LONG_LONG_MIN;
			for (ll len=L;len<=R;len++)
				for (ll l=max(i-len+1,1ll);l<=min(i,n-len+1);l++)
					temp=max(temp,a[l+len-1]-a[l-1]);
			ans^=((unsigned long long int)(i*temp));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
