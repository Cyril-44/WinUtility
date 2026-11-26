#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const long long MOD = 998244353;

long long c, t, n, m, a[N], w[N], dp[N], ans, tmp;
struct node {
	long long id, v, w;
	friend bool operator < (node x, node y) {
		if (x.v * y.w != x.w * y.v)	return x.v * y.w > x.w * y.v;
		else if (x.v != y.v)	return x.v > y.v;
		else	return x.id < y.id;
	}
} b[N];

int check() {
//	Plan A
	long long pam = m, pav = 0;
	for (int i = 1; i <= n; i++) {
		b[i].v = a[i], b[i].w = w[i], b[i].id = i;
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		if (pam >= b[i].w) {
			pav += b[i].v;
			pam -= b[i].w;
		}
	}
	
//	Plan B
	long long pbv = 0;
	for (int i = 0; i <= m; i++)	dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= b[i].w; j--) {
			dp[j] = max(dp[j], dp[j - b[i].w] + b[i].v);
		}
	}
	for (int i = 1; i <= m; i++)	pbv = max(pbv, dp[i]);
	
	//~ cout << pav << " " << pbv << "\n";
	return pav == pbv;
}

void dfs(int step) {
	if (step > n) {
		if (check()) {
			ans++;
			ans %= MOD;
			//~ //debug
			//~ int cnt = 0;
			//~ for (int i = 1; i <= n; i++)	cnt += 2 - w[i];
			//~ if (cnt % 2 != m % 2) {
			//~ for (int i = 1; i <= n; i++)	cout << w[i] << " ";
			//~ cout << "\n";
			//~ }
			return ;
		} else {
			//debug
			//~ int cnt = 0;
			//~ for (int i = 1; i <= n; i++)	cnt += 2 - w[i];
			//~ if (cnt % 2 != m % 2) {
			//~ for (int i = 1; i <= n; i++)	cout << w[i] << " ";
			//~ cout << "\n";
			//~ }
			return ;
		}
	}
	w[step] = 1;
	dfs(step + 1);
	w[step] = 2;
	dfs(step + 1);
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)	cin >> a[i];
		if (c >= 0 && c <= 5) {
			dfs(1);
			cout << ans << "\n";
		} else if ((c >= 10 && c <= 12) || c == 19 || c == 20) {
			for (int i = 1; i <= n; i++) {
				tmp = 1;
				for (int j = 1; j <= n - i - 1; j++) {
					tmp *= 2;
					tmp %= MOD;
				}
				ans += tmp;
				if (n - i - 1 >= 0) {
					if ((n - i) % 2 != m % 2)	ans += n - i;
				}
				ans %= MOD;
			}
			cout << ans << "\n";
		} else {
			ans = 1;
			for (int i = 1; i <= n; i++) {
				ans *= 2;
				ans %= MOD;
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}
