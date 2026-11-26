#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 10, inf = 1e14;
#define ull unsigned long long
int n, q;
int a[N];
int sum[N];
int f[N][25];
int lg[N];
typedef tuple <int, int, int> tup;
map <tup, int> mp;
int query(int u, int l, int r) {
	int len = r - l + 1;
	len = lg[len];
	return max(f[u + l - 1][len], f[u + r - 1 - (1ll << len) + 1][len]) - sum[u - 1];
}
// #define ls (u << 1)
// #define rs (u << 1 | 1)
// struct seg {
// 	int tr[N << 2];
// 	void pushup(int u) {
// 		tr[u] = max(tr[ls], tr[rs]);
// 	}
// 	void build(int u, int l, int r) {
// 		tr[u] = 0;
// 	}
// }
ull Ans;
ull qmul(int x, int y) {
	ull res = 0, X = x;
	while (y) {
		if(y & 1) res += X;
		X += X;
		y >>= 1;
	}
	return res;
}
signed main(void) {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
	cin >> n;
	for (int i = 2; i <= n + 5; i ++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		f[i][0] = sum[i];
	}
	for (int j = 1; j <= lg[n] + 1; j ++) {
		for (int i = 1; i <= n - (1ll << j) + 1; i ++) {
			f[i][j] = max(f[i][j - 1], f[i + (1ll << (j - 1))][j - 1]);
		}
	}
	cin >> q;
	while (q --) {
		int l, r;
		cin >> l >> r;
		Ans = 0;
		for (int i = 1; i <= n; i ++) {
			int k = -inf;
			for (int j = max(1ll, i - r + 1); j <= i; j ++) {
				int nl = max(l, i - j + 1), nr = min(r, n - j + 1);
				if(nl > nr) continue ;
				if(mp.count({j, nl, nr})) {
                    k = max(mp[{j, nl, nr}], k);
                    continue ;
				}
				int res = query(j, nl, nr);
				mp[{j, nl, nr}] = res;
				k = max(k, res);
			}
			//cout << k << endl;
			ull ans = k * i;
			Ans ^= ans;
		}
		cout << Ans << endl;
	}
	return 0;
}
