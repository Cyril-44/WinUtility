#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 5e3 + 10, pp = 998244353;
int C, T, n, m, a[N], p[N];
struct node {
	int a, w;
	bool operator < (const node &other) const {
		if (a * other.w != other.a * w) {
			return a * other.w > other.a * w;
		}
		return a > other.a;
	}
};
bool check() {
	int dp[m + 1];
	rep(i, 0, m) {
		dp[i] = 0;
	}
	rep(i, 1, n) {
		per(j, m, p[i]) {
			dp[j] = max(dp[j], dp[j - p[i]] + a[i]);
		}
	}
	int maxs = dp[m];
	node l[n + 1];
	rep(i, 1, n) {
		l[i] = {a[i], p[i]};
	}
	sort(l + 1, l + n + 1);
	int rem = m, cnt = 0;
	rep(i, 1, n) {
		if (rem >= l[i].w) {
			rem -= l[i].w;
			cnt += l[i].a;
		}
	}
	return maxs == cnt;
}
namespace _1_5 {
	int ans;
	void dfs(const int step) {
		if (step == n + 1) {
			if (check()) {
				++ ans;
			}
			return ;
		}
		p[step] = 1;
		dfs(step + 1);
		p[step] = 2;
		dfs(step + 1);
	}
};
int qpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = ret * a % pp;
		}
		a = a * a % pp;
		b >>= 1;
	}
	return ret;
}
signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> T;
	while (T --) {
		cin >> n >> m;
		rep(i, 1, n) {
			cin >> a[i];
		}
		if (C <= 5) {
			_1_5::ans = 0;
			_1_5::dfs(1);
			cout << _1_5::ans << '\n';
		} else if (C == 16) {
			cout << qpow(2, n) << '\n';
		} else if (C == 17) {
			sort(a + 1, a + n + 1);
			if (a[1] != a[2] && a[1] * 2 > a[2]) {
				cout << qpow(2, n) - 1 << '\n';
				// 2^n mod pp != 0
			} else {
				cout << qpow(2, n) << '\n';
			}
		}
	}
	return 0;
}
