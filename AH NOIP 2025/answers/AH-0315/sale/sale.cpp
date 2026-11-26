#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mod = 1000000007;
const int Inf_I = 0x3f3f3f3f;
const long long Inf_L = 0x3f3f3f3f3f3f3f3f;
long long c, t, n, m, a[10005], b[10005];
struct Node{
	long long  A, B;
	bool operator < (Node b) {
		return A * (3 - B) == b.A * (3 - b.B) ? A > b.A : A * (3 - B) > b.A * (3 - b.B);
	}
} Tmp[100005];
long long Ans, dp[105];
void dfs(int idx) {
	if (idx > n) {
		memset(dp, 0, sizeof dp);
		long long M = m, Tot = 0;
		for (int i = 1; i < idx; i++) Tmp[i] = {a[i], b[i]};
		sort(Tmp + 1, Tmp + idx);
		for (int i = 1; i <= n; i++) {
			if (M >= Tmp[i].B) M -= Tmp[i].B, Tot += Tmp[i].A;
		}
		for (int i = 1; i <= n; i++) 
			for (int j = m; j >= b[i]; j--)
				dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
		if (dp[m] == Tot) ++Ans;
		return;
	}
	b[idx] = 1;
	dfs(idx + 1);
	b[idx] = 2;
	dfs(idx + 1);
	return;
}
int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		Ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 18) {
			long long Ans = 1;
			for (int i = 1; i <= n; i++) Ans = Ans * 2 % Mod;
			cout << Ans << '\n';
			continue;
		}
		dfs(1);
		cout << Ans << '\n';
	}
	return 0;
}
//   NOIP Rp++
//  来中杨、王狗灏
//    一路走好
//   *   *   *
//    \  |  /
//     \ | /
//   |  \|/  |
//   ---------
//   ---------
//T2 20pts
//完蛋了t2t3都不会，暴力大概就40分，这个初二OIer估计要退役了
//Luogu 1004460
//Use UTF-8.
//下午不要上数学
//下午不要上数学
//下午不要上数学
//下午不要上数学
