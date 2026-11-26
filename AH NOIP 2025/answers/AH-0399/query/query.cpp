#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],l,r;
int main(){
	freopen ("query.in","r",stdin);
	freopen ("query.out","w",stdout);
	scanf ("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	for (int i=1;i<=q;i++){
		scanf ("%lld%lld",&l,&r);
		for (int i=1;i<=n-r+1;i++)
			mx=max(mx,a[r]-a[l-1]);
		printf ("%lld",mx);
	}
	return 0;
}
