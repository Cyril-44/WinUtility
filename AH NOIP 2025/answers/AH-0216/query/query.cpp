#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e4 + 1, MOD = (1 << 64);
int n, q, a[N], sum[N];
int val[N];
void work(int L, int R) {
	int ans = 0;
	for(int k = 1; k <= n; ++ k) {
		val[k] = LLONG_MIN;
		for(int i = 1; i <= n; ++ i) {
			if(i + L - 1 > k || i + R - 1 < k) continue;
			else if(i + R - 1 > n) continue;
			for(int j = k; j <= i + R - 1; ++ j) 
				val[k] = max(val[k], sum[j] - sum[i - 1]);
		}
		ans = ans ^ (k *  val[k]);
	}
	cout << ans << "\n";
	return;
}
signed main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	cin >> q;
	while(q --) {
		int L, R;
		cin >> L >> R;
		work(L, R);
	}
	return 0;
}
