#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3, Mod = 998244353;

int qpow(int n, int m) {
	int res = 1;
	while(m) {
		if(m & 1) res = 1ll * res * n  % Mod;
		n = 1ll * n * n % Mod;
		m >>= 1;
	}
	return res;
}
bool st;
int bas[N + 10], fac[N + 10], invf[N + 10];
namespace sub1 {
	struct node {
		int a, w;
		bool operator < (const node &other) const {
			if(a * other.w != other.a * w)
				return a * other.w < other.a * w;
			else return a < other.a;
		}
	} Q[N + 10];
	int n, m;
	int a[N + 10], w[N + 10];
	int S = 0;
	ll f[50][50];
	bool check() {
		for(int i = 0; i < n; i++)
			if(!((S >> i) & 1)) Q[i] = (node){a[i], 1};
			else Q[i] = (node){a[i], 2};
		sort(Q, Q + n);
		int rem = m;
		ll sum = 0, maxn = 0;
		for(int k = 0; k <= m; k++) f[n][k] = 0;
		for(int j = n - 1; j >= 0; j--) {
			for(int k = 0; k <= rem; k++) {
				f[j][k] = f[j + 1][k];
				if(k >= Q[j].w) f[j][k] = max(f[j + 1][k], f[j + 1][k - Q[j].w] + Q[j].a);
			}
		}
		maxn = f[0][rem];

		for(int i = n - 1; i >= 0; i--)
			if(rem >= Q[i].w) rem -= Q[i].w, sum += Q[i].a;
		return (maxn == sum);
	}
	void init() {

		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for(S = 0; S < (1 << n); S++) {
			ans += check();
		}	
		cout << ans << '\n';
	}
}
namespace subab {
	int qpow(int n, int m) {
		int res = 1;
		while(m) {
			if(m & 1) res = 1ll * res * n % Mod;
			n = 1ll * n * n % Mod;
			m >>= 1;
		}
		return res;
	}
	int n, m, a[N + 10];
	void init() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cout << qpow(2, n) << '\n';
	}
}
namespace subm2 {
	void upd(int &x, int y) {
		x = ((x + y >= Mod) ? (x + y - Mod) : (x + y));
	}
	int n, m, a[N + 10];
	void init() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];

		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);

		int ans = bas[n];

		for(int i = 2; i <= n; i++) {
			if(2 * a[i] > a[1]) upd(ans, Mod - 1);
			for(int j = i + 1; j <= n; j++) {
				if(2 * a[i] > a[1] && a[i] + a[j] < a[1])
					upd(ans, Mod - bas[n - j]);
			}
			// if(a[i] <= a[1]) upd(ans, 1);
		}
		cout << ans << '\n';
	}
}
namespace subb {
	void upd(int &x, int y) {
		x = ((x + y >= Mod) ? (x + y - Mod) : (x + y));
	}
	int n, m, a[N + 10];
	int C(int n, int m) {
		if(m > n) return 0;
		return 1ll * fac[n] * invf[m] % Mod * invf[n - m] % Mod;
	}
	void init() {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		int ans = bas[n];
		for(int i = 1; i <= n; i++) {
			for(int t = 1; t <= min(i - 1, m); t++) {
				if((m - t) % 2 == 0) continue;
				if(2 * (i - t) + t > m) {
					// cout << i << ' ' << t << endl;
					upd(ans, Mod - C(i - 1, t - 1));
				}
			}
		}
		cout << ans << '\n';
	}
}
bool ed;
signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bas[0] = 1, fac[0] = 1;
	for(int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
	invf[N] = qpow(fac[N], Mod - 2);
	for(int i = N - 1; i >= 0; i--) invf[i] = 1ll * invf[i + 1] * (i + 1) % Mod;
	for(int i = 1; i <= N; i++)
		bas[i] = 2ll * bas[i - 1] % Mod;
	int cas, T;
	cin >> cas >> T;
	if(cas <= 5)
		while(T--) sub1::init();
	else if(cas == 18 || cas == 16) while(T--) subab::init();
	else if(cas >= 7 && cas <= 9) while(T--) subm2::init();
	else if(cas >= 14 && cas <= 15) while(T--) subm2::init();
	else if(cas >= 10 && cas <= 12 || 
		cas >= 19 && cas <= 20) while(T--) subb::init();
	// cerr << (&ed - &st) / 1024.0 / 1024.0 << '\n';
}