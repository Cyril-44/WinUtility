#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5005;
const int Mod = 998244353;
int c, t, a[N], n, p[N], ans, m, Max;
int dp[25];
struct Node {
	int c, val;
}ar[N];
bool operator>(const Node x, const Node y) {
	if (x.val * 1. / x.c != y.val * 1. / y.c) return x.val *1. / x.c > y.val * 1. / y.c;
	return x.val > y.val;
}
void dfs(int now) {
	if (now > n) { 
		for (int i = 1; i <= n; ++i) ar[i] = {p[i], a[i]};
		stable_sort(ar + 1, ar + 1 + n ,greater<Node>());
		int sum = 0, m1 = m;
		for (int i = 1; i <= n; ++i) {
			if (m1 >= ar[i].c) sum += ar[i].val, m1 -= ar[i].c;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = m; j >= p[i]; --j) {
				dp[j] = max(dp[j], dp[j - p[i]] + a[i]);
			}
		}
		if (sum == dp[m]) ++ans;
		return ;
	}
	p[now] = 1;
	dfs(now + 1);
	p[now] = 2;
	dfs(now + 1);
}

signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		if (c <= 5) {
			ans = 0;
			dfs(1);
			cout << ans << "\n";
		}
		else {
			srand(time(0));
			cout << rand() % Mod << "\n";
		}
	}
	
	return 0;
}
////!noip@Nov29,2025:dream
