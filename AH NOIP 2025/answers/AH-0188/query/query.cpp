#include <bits/stdc++.h>
using namespace std;
int n, q, a[50005], l, r;
int main(){
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
		scanf("%d %d", &l, &r);
		long long k=1;
		for(int j=1; j<=r-l+1; j++)
		    k*=2;
		printf("%lld\n", k);
	}
    return 0;
}
