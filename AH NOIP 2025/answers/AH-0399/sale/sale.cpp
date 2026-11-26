#include <bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[5005],op1=1,op2=2;
long long pw(long long k){
	if (k==0)
		return 1;
	return (2*pw(k-1))%998244353;
}
int main(){
	freopen ("sale.in","r",stdin);
	freopen ("sale.out","w",stdout);
	scanf ("%lld%lld",&c,&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		for (int i=1;i<=n;i++){
			scanf ("%lld",&a[i]);
			if (a[i]!=a[1])
				op1=0;
		}
		sort (a+1,a+n+1);
		long long qx=pw(n);
		if (op1||m==(2*n-1)){
			printf ("%lld\n",qx);
		}
	}
	return 0;
}
