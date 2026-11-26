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

const int N = 1e5 + 10;

int n;

ll m;

ll a[N];

ll sum[N];

ll ans = 0,tmp = 0;

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ll c = infL;
	scanf("%d%lld",&n,&m);
	rep(i,1,n){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		a[i] = x;
		c = min(c,x + y);
	}
	sort(a + 1,a + 1 + n);
	rep(i,1,n) sum[i] = sum[i - 1] + a[i];
	rep(i,1,n){
		ll res = tmp;
		ll t = m;
		res += (t / c) * 2;
		t %= c;
		int l = i - 1,r = n + 1;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(sum[mid] - sum[i - 1] <= t) l = mid;
			else r = mid;
		}
		res += l - i + 1;
		ans = max(ans,res);
		if(m >= a[i]){
			m -= a[i];
			tmp++;
		}else{
			break;
		}
	}
	ans = max(ans,tmp + (m / c) * 2);
	printf("%lld",ans);
	return 0;
}