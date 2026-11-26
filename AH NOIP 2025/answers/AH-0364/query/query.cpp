#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 5e4 + 10;
int n, q, a[N], t[N * 4];
void build(const int now, const int tl, const int tr) {
	if (tl == tr) {
		t[now] = a[tl];
		return ;
	}
	const int mid = (tl + tr) / 2;
	build(now * 2, tl, mid);
	build(now * 2 + 1, mid + 1, tr);
	t[now] = t[now * 2] + t[now * 2 + 1];
}
int query(const int now, const int tl, const int tr, const int l, const int r) {
	if (tl >= l && tr <= r) {
		return t[now];
	}
	const int mid = (tl + tr) / 2;
	if (r <= mid) {
		return query(now * 2, tl, mid, l, r);
	}
	if (l > mid) {
		return query(now * 2 + 1, mid + 1, tr, l, r);
	}
	return query(now * 2, tl, mid, l, r)
	     + query(now * 2 + 1, mid + 1, tr, l, r);
}
int query(const int l, const int r) {
	return query(1, 1, n, l, r);
}
signed main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	build(1, 1, n);
	cin >> q;
	while (q --) {
		int L, R;
		cin >> L >> R;
		unsigned int ans = 0;
		rep(i, 1, n) {
			int _ans = LONG_LONG_MIN;
			rep(j, L, R) {
				rep(k, max(1ll, i - j + 1), min(i, n - j + 1)) {
					_ans = max(_ans, query(k, k + j - 1));
				}
			}
			ans ^= (unsigned int)i * (unsigned int)_ans;
		}
		cout << ans << '\n';
	}
	return 0;
}
// O(q n^3 log n)
