#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 1e5 + 10;
int n, m, a[N], b[N];
int div_ceil(const int x, const int y) {
	return max(0ll, (x + y - 1) / y);
}
signed main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	int min_sum = LONG_LONG_MAX;
	rep(i, 1, n) {
		cin >> a[i] >> b[i];
		min_sum = min(min_sum, a[i] + b[i]);
	}
	sort(a + 1, a + n + 1);
	int cnt = m / min_sum * 2;
	int rem = m % min_sum;
	int p = 1, lim = m / min_sum;
	for (; p <= n; ++ p) {
		if (rem >= a[p]) {
			rem -= a[p];
			++ cnt;
		} else {
			break;
		}
	}
	int ans = cnt;
	while (p <= n) {
		// rem + x * min_sum >= a[p]
		// x >= (a[p] - rem) / min_sum
		if (a[p] > rem) {
			int times = div_ceil(a[p] - rem, min_sum);
			lim -= times;
			if (lim < 0) {
				break;
			}
			cnt -= times * 2, rem += times * min_sum;
		}
		rem -= a[p], ++ cnt;
		++ p;
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
