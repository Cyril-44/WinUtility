#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005, mod = 998244353;
int a[N];
int c, tt;
int n, m;
bool cmp(int x, int y) {
	return x > y;
}
int qpow(int x, int a) {
	int res = 1;
	while (a) {
		if(a & 1) res *= x;
		x *= x;
		x %= mod;
		res %= mod;
		a >>= 1;
	}
	return res % mod;
}
int inv[N], jc[N];
void rest() {
	jc[0] = 1;
	for (int i = 1; i <= 5000; i ++) jc[i] = jc[i - 1] * i % mod;
	for (int i = 1; i <= 5000; i ++) inv[i] = qpow(jc[i], mod - 2);
}
int C(int x, int y) {
	int res = jc[x];
	res = res * inv[y] % mod * inv[x - y] % mod;
	return res;
}
signed main(void) {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> c >> tt;
	rest();
	while (tt --) {
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		int flag = 0;
		for (int i = 1; i < n; i ++) if(a[i] != a[i + 1]) flag = 1;
		if(!flag) {
			if(m & 1) cout << 0 << endl;
			else {
				int ans = 0;
				for (int i = 1; i <= n; i += 2) {
					ans += C(n, i);
					ans %= mod;
				}
				cout << ans << endl;
			}
		}
	}
}
