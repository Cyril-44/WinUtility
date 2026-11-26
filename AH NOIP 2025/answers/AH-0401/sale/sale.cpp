#include<bits/stdc++.h>
using namespace std;
long long C,T,n,m,h,cnt,a[5010];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld %lld",&C,&T);
	while(T--){
		scanf("%lld %lld",&n,&m);
		for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
		printf("%lld\n",n+a[1]);
	}
	return 0;
}
