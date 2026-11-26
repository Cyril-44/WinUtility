#include<bits/stdc++.h>
using namespace std;


const long long N = 5005, P = 998244353;
const double eps = 1e-8;

struct node {
	long long x, w;
	double re;
	friend bool operator < (const node a, const node b) {
		if (fabs (a.re - b.re) > eps) return a.re > b.re;
		return a.x > b.x;
	}
};

long long a[N], dp[N][N];
node temp[N];

long long qpow (long long base, long long times) {
	if (times == 0) return 1;
	long long temp = qpow (base, (times >> 1));
	if (times & 1) return temp * temp % P * base % P;
	return temp * temp % P;
}

int main () {
	freopen ("sale.in", "r", stdin);
	freopen ("sale.out", "w", stdout);
	long long c, t, m, tm, ans = 0, cnt, n, maxn, mat, minm;
	bool flag;
	cin >> c >> t;
	while (t--) {
		cin >> n >> m, cnt = maxn = mat = 0, minm = LLONG_MAX;
		for (long long i = 1; i <= n; ++i) cin >> a[i];
		if (c <= 5) {
			for (long long i = 0; i <= (1 << n) - 1; ++i) {
				for (long long j = 1; j <= n; ++j) {
					temp[j].x = a[j], temp[j].w = (((i >> (j - 1)) & 1) == 1 ? 2 : 1), temp[j].re = static_cast<double> (a[j]) / temp[j].w;
				}
				sort (temp + 1, temp + 1 + n), tm = m, ans = 0;
				for (long long j = 1; j <= n; ++j) if (tm >= temp[j].w) ans += temp[j].x, tm -= temp[j].w;
				for (long long j = 1; j <= n; ++j) {
					for (long long k = 1; k <= m; ++k) {
						if (k >= temp[j].w) dp[j][k] = dp[j - 1][k - temp[j].w] + temp[j].x;
						dp[j][k] = max (dp[j][k], dp[j - 1][k]);
					}
				}
				if (ans == dp[n][m]) ++cnt;
				for (long long j = 1; j <= n; ++j) for (long long k = 1; k <= m; ++k) dp[j][k] = 0;
			}
			cout << cnt << endl;
			continue;
		}
		if (c == 16 || c == 18) {
			cout << qpow (2, n) << endl;
			continue;
		}
		if (c == 17) {
			for (int i = 1; i <= n; ++i) {
				if (a[i] < minm) minm = a[i], mat = 1;
				else if (a[i] == minm) ++mat;
			}
			for (int i = 1; i <= n; ++i) {
				flag = true;
				for (int j = 1; j <= n; ++j) {
					if (j == i) continue;
					if (2 * a[i] > a[j] && a[i] == minm) flag = false;
				}
				if (flag == false) ++cnt;
			}
			cout << (qpow (2, n) - (mat == 1 && cnt > 0)) % P << endl;
		}
		if (m == 2) {
			for (int i = 1; i <= n; ++i) {
				if (a[i] > maxn) maxn = a[i], mat = 1;
				else if (a[i] == maxn) ++mat;
			}
			for (int i = 1; i <= n; ++i) if (a[i] * 2 <= maxn) ++cnt;
			ans = (qpow (2, cnt) + mat) % P, sort (a + 1, a + 1 + n, greater <long long> ());
			for (int i = 1; i <= n; ++i) {
				for (int j = i + 1; j <= n; ++j) {
					if (a[i] + a[j] < maxn || a[i] * 2 <= maxn) continue;
					ans = (ans + qpow (2, n - j)) % P;
				}
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
