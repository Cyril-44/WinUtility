#include<bits/stdc++.h>
using namespace std;


const long long N = 5e4 + 5, M = 20;

long long a[N], sum[N][M];

long long query (long long l, long long r) {
	if (l > r) return LLONG_MIN / 2;
	long long k = log2 (r - l + 1);
	return max (sum[l][k], sum[r - (1 << k) + 1][k]);
}

int main () {
	freopen ("query.in", "r", stdin);
	freopen ("query.out", "w", stdout);
	long long n, q, lst = 1, cnt, temp, l, r;
	unsigned long long ans;
	cin >> n;
	for (long long i = 1; i <= n; ++i) cin >> a[i], sum[i][0] = sum[i - 1][0] + a[i];
	for (long long i = 1; i <= 19; ++i) {
		for (long long j = 1; j + (1 << i) - 1 <= n; ++j) sum[j][i] = max (sum[j][i - 1], sum[j + (1 << (i - 1))][i - 1]);
	}
	cin >> q;
	for (long long i = 1; i <= q; ++i) {
		cin >> l >> r, lst = 0, ans = 0;
		for (long long j = 1; j <= n; ++j) {
			cnt = LLONG_MIN;
			for (long long k = max (lst, j - r); k < j; ++k) {
				temp = query (max (j, l + k), min (r + k, n)) - sum[k][0];
				if (temp > cnt) cnt = temp, lst = k;
			}
			ans ^= (static_cast <unsigned long long> (j) * static_cast <unsigned long long> (cnt));
		}
		cout << ans << endl;
	}
	return 0;
}
