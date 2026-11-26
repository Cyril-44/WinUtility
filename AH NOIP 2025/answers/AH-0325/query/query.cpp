#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define inf 1e18
const int N = 5e4 + 5;
int n, q;
ll a[N], sum[N];
int l[N], r[N];
ll f[3005][3005];

bool issubB() {
	for(int i = 1; i <= q; i++)
		if(r[i] > 32) return false;
	return true;
}
namespace subB {
	ll f[N][45];
	void main() {
		for(int len = 1; len <= 32; len++) {
			for(int i = 1; i <= n; i++)
				f[i][len] = -inf;
			for(int i = 1, j = len; j <= n; i++, j++) 
				for(int k = i; k <= j; k++)
					f[k][len] = max(f[k][len], sum[j] - sum[i - 1]);
		}
		for(int _ = 1; _ <= q; _++) {
			ull ans = 0;
			for(int i = 1; i <= n; i++) {
				ll tot = -inf;
				for(int len = l[_]; len <= r[_]; len++)
					tot = max(tot, f[i][len]);
				ans ^= (ull)tot * i;
			}
			cout << ans << endl;
		}
	}
}

int main() {
  freopen("query.in", "r", stdin);
  freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	cin >> q;
	for(int i = 1; i <= q; i++)
		cin >> l[i] >> r[i];
	if(issubB()) {
		subB::main();
		return 0;
	}
	for(int len = 1; len <= n; len++) {
		for(int i = 1; i <= n; i++)
			f[i][len] = -inf;
		for(int i = 1, j = len; j <= n; i++, j++) 
			for(int k = i; k <= j; k++)
				f[k][len] = max(f[k][len], sum[j] - sum[i - 1]);
	}
	for(int _ = 1; _ <= q; _++) {
		ull ans = 0;
		for(int i = 1; i <= n; i++) {
			ll tot = -inf;
			for(int len = l[_]; len <= r[_]; len++)
				tot = max(tot, f[i][len]);
			ans ^= (ull)tot * i;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
 * luogu @xler0915
 * Goodbye, OI */
