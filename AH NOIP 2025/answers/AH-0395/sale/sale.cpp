#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=998244353;
ll c, t, n, m, a[5005], f[20005], ans, k[50005];
int tmp=0;
struct node{
    ll a, w, id;
}p[5005];
bool cmp(node x, node y){
	if(x.a*y.w==x.w*y.a){
		if (x.a!=y.a) return x.a>y.a;
		else return x.id<y.id;
	}
    return x.a*y.w>x.w*y.a;
}
bool cmp1(node x, node y){
	return x.id<y.id;
}
void dfs(int x){
    if (x>n){
        sort(p+1, p+n+1, cmp);
        ll s=m;
        ll sum1=0;
        for (ll i=1; i<=n; i++){
			if (s>=p[i].w){
				sum1+=p[i].a;
				s-=p[i].w;
			}
		}
		sort(p+1, p+n+1, cmp1);
		memset(f, 0, sizeof(f));
		for (ll i=1; i<=n; i++){
			for (ll j=m; j>=p[i].w; j--){
				f[j]=max(f[j], f[j-p[i].w]+p[i].a);
			}
		}
		if (sum1==f[m]) ans=(ans+1)%mod;
		return;
	}
	p[x].w=1;
	dfs(x+1);
	p[x].w=2;
	dfs(x+1);
	return;
}
void tsa(){
	ans=1;
	for (ll i=1; i<=n; i++){
		ans=(ans*2)%mod;
	}
	printf("%lld\n", ans);
}
int main(){
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >>t;
    while (t--){
		ans=0;tmp=0;
        scanf("%lld%lld", &n, &m);
        for (int i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            p[i].a=a[i];p[i].id=i;
            if (p[i].a!=p[1].a) tmp=1;
        }
        if (!tmp){
	        tsa();
	        continue;
	    }
        /*if (m==2*n){
            ts1();
            continue;
        }*/
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
/*
0 2
4 4
3 3 3 3
5 7
8 8 8 8 8
*/
