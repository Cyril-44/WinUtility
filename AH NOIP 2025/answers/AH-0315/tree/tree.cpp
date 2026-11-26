#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mod = 1000000007;
const int Inf_I = 0x3f3f3f3f;
const long long Inf_L = 0x3f3f3f3f3f3f3f3f;
int dp[80005][2];
struct Edge {
	int to, ne;
} E[80005];
int H[80005], cnt, Num[80005], t, n, m;
int Hel[80005], Dep[80005];
void Add(int u, int v) {
	E[++cnt] = {v, H[u]};
	H[u] = cnt;
	return ;
}
void Solve(int idx, int fa, int dep) {
	Dep[idx] = dep;
	++Num[idx];
	bool Leaf = 1;
	for (int i = H[idx]; i; i = E[i].ne) {
		int j = E[i].to;
		if (j == fa) continue;
		Leaf = 0;
		Solve(j, idx, dep + 1);
		Dep[idx] = max(Dep[idx], Dep[j]);
		Num[idx] += Num[j];
	}
	int Lefn = 0;
	for (int i = H[idx]; i; i = E[i].ne) {
		int j = E[i].to;
		if (j == fa) continue;
		++Lefn;
		long long Tot = dp[j][0], He = Hel[j] + 1, Yuan = Hel[j];
		for (int k = H[idx]; k; k = E[k].ne) {
			int J = E[k].to;
			if (J == j || J == fa) continue;
			if (dep * Num[J] < dp[J][0]) {
				Tot += dp[J][0];
				if (Hel[J] > Yuan) He -= Yuan, He += Hel[J], Yuan = Hel[J];
			}
			else He += Num[J];
		}
		if (dp[idx][0] == 0) dp[idx][0] = Tot + He, Hel[idx] = He;
		else if (dp[idx][0] + Hel[idx] * (dep - 1) < Tot + He * dep) dp[idx][0] = Tot + He, Hel[idx] = He;
	}
	//if (dp[idx][0] + Hel[idx] * (dep - 1) < )
	if (Leaf) dp[idx][0] = 1, Hel[idx] = 1;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cnt = 0;
		memset(H, 0, sizeof H);
		memset(dp, 0, sizeof dp);
		memset(Hel, 0, sizeof Hel);
		memset(Num, 0, sizeof Num);
		memset(Dep, 0, sizeof Dep);
		for (int i = 2; i <= n; i++) {
			int v;
			cin >> v;
			Add(v, i);//Only U to V
		}
		Solve(1, 0, 1);
		cout << dp[1][0] << '\n';
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
//T3 20pts
//Use UTF-8.

