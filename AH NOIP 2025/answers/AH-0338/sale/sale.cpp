#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define F(x) ((x) % P)
#define FE(x) ((x) %= P)
using namespace std;	
using ll = long long;
using db = double;
using PII = pair<int,int>;
using PLL = pair<ll,ll>;
constexpr int infI = 1 << 30;
constexpr ll infL = 1ll << 60;

int c;

const int N = 5010;

const int P = 998244353;

ll fac[N],fac_inv[N];

ll qpow(ll x,ll y){
	ll res = 1;
	for(;y;y >>= 1){
		if(y & 1) FE(res *= x);
		FE(x *= x);
	}
	return res;
}

void init(){
	fac[0] = 1;
	rep(i,1,N - 5) FE(fac[i] = fac[i - 1] * i);
	fac_inv[N - 5] = qpow(fac[N - 5],P - 2);
	per(i,0,N - 5 - 1) FE(fac[i] = fac[i + 1] * (i + 1));
}

ll C(ll x,ll y){
	if(x < 0 || y < 0) return 0;
	return F(F(fac[x] * fac_inv[y]) * fac_inv[x - y]);
}

int n,m;

ll anss;

ll a[N];

int b[N];

PLL dd[N],e[N];

ll ff[2 * N + 5];

void dfs(int u){
	if(u == n + 1){
		memset(ff,0,sizeof(ff));
		ll mm = m;
		ll res = 0;
		memcpy(e,dd,sizeof(e));
		sort(e + 1,e + 1 + n,[](PLL x,PLL y){
			if(x.fi * y.se == y.fi * x.se){
				return x.fi > y.fi;
			}
			return x.fi * y.se > y.fi * x.se;
		});
		rep(i,1,n){
			if(mm >= e[i].se){
				mm -= e[i].se;
				res += e[i].fi;
			}
		}
		rep(i,1,n){
			per(j,e[i].se,m){
				ff[j] = max(ff[j],ff[j - e[i].se] + e[i].fi);
			}
		}
		anss += (ff[m] == res);

	}else{
		dd[u].fi = a[u];
		dd[u].se = 1;
		dfs(u + 1);
		dd[u].se = 2;
		dfs(u + 1);
	}
}

void clear(){

}

void solve(){
	scanf("%d%d",&n,&m);
	if(c == 18){
		printf("%lld\n",qpow(2,n));
		return ;
	}
	ll ans = qpow(2,n);
	vector<int> arr;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		arr.pb(a[i]);
	}
	if(c <= 5) {
		anss = 0;
		dfs(1);
		printf("%lld\n",anss);
		return ;
	}
	sort(all(arr));
	sort(a + 1,a + 1 + n);
	arr.erase(unique(all(arr)),arr.end());
	rep(i,1,n){
		b[lower_bound(all(arr),a[i]) - arr.begin() + 1]++;
	}
	rep(i,1,n) b[i] = b[i - 1] + 1;
	if(c == 10 || c == 11 || c == 12 || c == 19 || c == 20){
		rep(l,1,n){
			if((m - l) % 2 == 0) continue;
			rep(k,2,n){
				ll h = b[lower_bound(all(arr),a[k]) - arr.begin() + 1];
				rep(p,k - 1,n){
					ll t = b[lower_bound(all(arr),a[p] + a[k]) - arr.begin() + 1];
					ll g = (m - l + 1) / 2;
					ans -= F(C(t,g) * C(h - t,l));
					ans += P;
					ans %= P;
				}
			}
		}
	}
	printf("%lld\n",ans);
}


int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	init();
	int T;
	scanf("%d%d",&c,&T);
	while(T--){
		clear();
		solve();
	}
	return 0;
}