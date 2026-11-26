#include<bits/stdc++.h>
#define ll __int128
using namespace std;

const int N = 50005;
const ll p = ll(1 << 64);

ll n, q, mn, ma;
ll a[N];

struct Tree {
	ll val[N];
	void pushup(ll u) {
		val[u] = val[u << 1] + val[u << 1 | 1];
	}
	void build(ll u, ll l, ll r) {
		if (l == r) {
			val[u] = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	ll query(ll u, ll l, ll r, ll L, ll R) {
		if (L <= l && r <= R) return val[u];
		ll mid = (l + r) >> 1; ll ans = 0;
		if (L <= mid) ans += query(u << 1, l, mid, L, R);
		if (R > mid) ans += query(u << 1 | 1, mid + 1, r, L, R);
		return ans;
	}
}t;

void in(ll &x) {
	x = 0; ll f = 1;
	char c = getchar();
	while (c < '0' && c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= f;
}

ll qpow(ll a, ll b){
	ll ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = (ret * a);
		a = (a * a);
	//	cout << a << ' ' << ret << endl;
	}
	return ret;
}

void out(ll x) {
	if (x == 0) return;
	out(x / 10);
	// char c = (x % 10) + '0';
	putchar(char((x % 10) + '0'));
}

int main() {
	 freopen("query.in", "r", stdin);
	 freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	in(n);
	//out(qpow(2, 64)); cout << endl;
	for (ll i = 1; i <= n; i ++) in(a[i]);
	t.build(1, 1, n); in(q);
	while (q --) {
		ll ans = 0;
		in(mn); in(ma);
		for (ll i = 1; i <= n; i ++) {
			//cout << i << endl;
			ll k = -(p - 1);
			// cout << i << endl;
			/*for (ll len = mn; len <= ma; len ++) {
				ll l = i, r = i;
				while (l > 1 && r - l + 1 < len) l --;
				while (r - l + 1 < len && r < n) r ++;
				while (r <= n && l <= i) {
					k = max(k, t.query(1, 1, n, l, r));
					l ++, r ++;
				}
				cout << l << ' ' << r << endl;
			}*/
			// cout << i << endl;
			ans = ((ans ^ ((i * k) % p))) % p;
			// cout << i << endl;
			if (ans < 0) ans = (ans + p) % p;
			// cout << i << endl;
		}
		if (ans < 0) putchar('-'), ans *= -1;
		out(ans); cout << '\n';
	}
	return 0;
}
/*
4
2 4 ‐5 1
3
1 2
3 4
1 4
*/
