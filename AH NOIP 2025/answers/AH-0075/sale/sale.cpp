#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5010;
const ll mod = 998244353;
ll qpow(ll n,int m){
	if(m == 0) return 1ll;
	if(m == 1) return n;
	ll res = qpow(n, m/2);
	if(m%2) return res * res % mod * n % mod;
	return res * res % mod;
}
int n,m,res,w[N];
ll a[N],f[2*N];
struct node{
	ll value;
	int id;
}b[N];
bool cmp(node x,node y){
	if(x.value == y.value){
		if(a[x.id] == a[y.id])
			return x.id < y.id;
		return a[x.id] > a[y.id];
	}
	return x.value > y.value;
}
void dfs(int cur){
	if(cur == n+1){
		for(int i=1;i<=n;i++){
			b[i].id = i;
			b[i].value = a[i]/(w[i]*1ll);
		}
		sort(b+1,b+n+1,cmp);
		int sumw = 0;ll sum = 0;
		for(int i=1;i<=n;i++){
			if(sumw+w[b[i].id] > m) continue;
			sumw += w[b[i].id];
			sum += a[b[i].id];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--){
				f[j] = max(f[j],f[j-w[i]]+a[i]);
			}
		}
		if(sum == f[m]){
			res++;
		}
		for(int j=0;j<=m;j++){
			f[j] = 0;
		}
		return;
	}
	w[cur] = 1;
	dfs(cur+1);
	w[cur] = 2;
	dfs(cur+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i] *= 2;
		}
		if(m == 2*n-1){
			ll ans = qpow(2ll,n);
			printf("%lld\n",ans);
		}
		else if(n <= 10){
			dfs(1);
			printf("%d\n",res);
			res = 0;
		}
		else if(m == 2){
			ll ans = qpow(2ll,n-1);
			sort(a+1,a+n+1);
			int t = lower_bound(a+1,a+n+1,a[n]/2)-a-1;
			if(t == 1){
				ans = qpow(2ll,n);
			}else{
				int l = 1,r = n-1;
				while(r >= t){
					while(l < t && a[l] + a[r] < a[n])
						l++;
					ans = ((ans + qpow(2ll,r-1))%mod - qpow(2ll,l-1) + mod) % mod;
					r--;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
