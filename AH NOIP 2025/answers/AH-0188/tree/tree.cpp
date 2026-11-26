#include <bits/stdc++.h>
using namespace std;
int t, n, m, p[8005];
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
		int ans=0;
		scanf("%d %d", &n, &m);
		p[1]=0;
		for(int i=2; i<=n; i++)
		     scanf("%d", &p[i]);
		for(int i=2; i<=n-1; i++)
		     ans+=p[i]+1;
		printf("%d\n", ans);
	}
    return 0;
}
