#include<bits/stdc++.h>
using namespace std;
long long n,q,l,r,a[50005],p[50005],mx[50005];
unsigned long long s;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		p[i]=p[i-1]+a[i];
	}
	scanf("%lld",&q);
	while(q--){
		scanf("%lld%lld",&l,&r);
		for(long long i=1;i<=n;i++){
			mx[i]=-0x7fffffffffffffff;
			for(long long j=max(i-r+1,1ll);j<=i;j++) for(long long k=j+l-1;k<=min(j+r-1,n);k++) if(j<=i&&i<=k) mx[i]=max(mx[i],p[k]-p[j-1]);
		}
		for(long long i=1;i<=n;i++) s^=i*mx[i];
		printf("%llu\n",s);
		s=0;
	}
	return 0;
}
