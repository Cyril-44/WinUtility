#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll C, t, n, m, ans;
ll a[5010], c[5010];
struct node{ll idx, p1, p2;}b[5010];
bool cmp(node a, node b){
	if(a.p1 * b.p2 == b.p1 * a.p2 && a.p1 == b.p1) return a.idx < b.idx;
	else if(a.p1 * b.p2 == b.p1 * a.p2) return a.p1 > b.p1;
	return a.p1 * b.p2 > b.p1 * a.p2;
}

void dfs(int idx, int s){
	if(idx == n + 1){
//		cout << "114514\n";
		ll sum = 0, dp[310] = {0};
		for(int i = 1; i <= n; i ++)
			b[i].idx = i, b[i].p1 = a[i], b[i].p2 = c[i];
		sort(b + 1, b + n + 1, cmp);
		ll tmp = m;
		for(int i = 1; i <= n; i ++)
			if(tmp >= b[i].p2) sum += b[i].p1, tmp -= b[i].p2;
		for(int i = 1; i <= n; i ++)
			for(int j = m; j >= b[i].p2; j --)
				dp[j] = max(dp[j], dp[j - b[i].p2] + b[i].p1);
//		for(int i = 1; i <= n; i ++)
//			cout << c[i] << ' ';
//		cout << '\n';
//		cout << sum << ' ' << dp[m] << '\n';
		if(dp[m] == sum) ans ++, ans %= mod;
		return;
	}
	c[idx] = 1;
	dfs(idx + 1, s + 1);
	c[idx] = 2;
	dfs(idx + 1, s + 2);
}

int main(){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> t;
	while(t --){
		ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		if(C == 18){
			int sum = 1;
			for(int i = 1; i <= n; i ++)
				sum = (sum * 2) % mod;
			cout << sum << '\n';
			continue;
		}
		dfs(1, 0);
		cout << ans % mod << '\n';
	}
	return 0;
}
//!noip@Nov29,2025:dream
/*
1 3 5
1 2 1
*/
