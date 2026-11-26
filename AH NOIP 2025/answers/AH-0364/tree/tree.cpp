#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 8e3 + 10;
int T, n, m, fa[N];
vector <int> g[N];
int ans;
int dfs(const int u) {
	int col = -1;
	for (const auto v : g[u]) {
		col = max(col, dfs(v));
	}
	++ col;
	ans += col + 1;
	return col;
}
namespace vio {
	int col[20], sum, ans;
	void merge(set <int> &x, const set <int> &y) {
		for (const auto i : y) {
			x.insert(i);
		}
	}
	int mex(const set <int> &s) {
		if (s.empty()) {
			return 0;
		}
		int exp = 0;
		for (const auto i : s) {
			if (i != exp) {
				return exp;
			}
			++ exp;
		}
		return exp;
	}
	set <int> calc(const int u) {
		set <int> ret;
		ret.insert(col[u]);
		for (const auto v : g[u]) {
			merge(ret, calc(v));
		}
		sum += mex(ret);
		return ret;
	}
	void paint(const int step) {
		if (step == n + 1) {
			sum = 0;
			calc(1);
			ans = max(ans, sum);
			return ;
		}
		rep(i, 0, n - 1) {
			col[step] = i;
			paint(step + 1);
		}
	}
};
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T --) {
		cin >> n >> m;
		rep(i, 1, n) {
			g[i].clear();
		}
		rep(i, 2, n) {
			cin >> fa[i];
			g[fa[i]].push_back(i);
		}
		if (n <= 7) {
			vio::ans = 0;
			vio::paint(1);
			cout << vio::ans << '\n';
		} else {
			dfs(1);
			cout << ans << '\n';
		}
	}
	return 0;
}














// noip 没 1= 了 /ll 该怎么活下去
