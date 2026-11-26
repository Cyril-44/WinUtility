#include<bits/stdc++.h>
using namespace std;
long long n,a[50010],q,lj,rj,h[50010],yh;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		h[i]=h[i-1]+a[i];
	}
	scanf("%lld",&q);
	while(q--){
		yh=0;
		scanf("%lld %lld",&lj,&rj);
		for(long long i=1;i<=n;i++){
			long long maxs=-1e18;
			for(long long len=lj;len<=rj;len++){
				for(long long j=max(i,len);j<=min(n,i+len-1);j++)
					maxs=max(maxs,h[j]-h[j-len]);
			}
			yh=yh^(maxs*i);
		}
		printf("%llu\n",(unsigned long long)(yh+18446744073709551616));
	}
	return 0;
}
