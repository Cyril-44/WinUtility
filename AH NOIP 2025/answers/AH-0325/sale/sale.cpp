#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int P = 998244353;
int c, t;
int n, m;
int a[5005];

namespace subA {
	void main() {
		ll ans = 1;
		for(int i = 1; i <= n; i++)
			ans = ans * 2 % P;
		cout << ans << endl;
	}
}
namespace baoli {
	int ans = 0;
	struct node {
		int a, w, id;
		double pl;
		bool operator< (const node& _) {
			if(pl != _.pl) return pl > _.pl;
			if(a != _.a) return a > _.a;
			return id < _.id;
		}
	} candy[5005], tmpcandy[5005];
	ll dp[10005];
	bool check() {
		for(int i = 1; i <= n; i++)
			tmpcandy[i] = candy[i];
		sort(tmpcandy + 1, tmpcandy + n + 1);
		ll wrongans = 0; int tmpm = m;
		for(int i = 1; i <= n; i++) {
			if(tmpm >= tmpcandy[i].w) {
				tmpm -= tmpcandy[i].w;
				wrongans += tmpcandy[i].a;
			}
		}
		for(int i = 1; i <= m; i++)
			dp[i] = -0x3f3f3f3f3f3f3f3f;
		dp[0] = 0ll;
		for(int i = 1; i <= n; i++)
			for(int j = m; j >= candy[i].w; j--)
				dp[j] = max(dp[j], dp[j - candy[i].w] + candy[i].a);
		ll rightans = 0;
		for(int i = 1; i <= m; i++)
			rightans = max(rightans, dp[i]);
		return wrongans == rightans;
	}
	void main() {
		ans = 0;
		for(int i = 1; i <= n; i++)
			candy[i].a = a[i], candy[i].id = i;
		for(int i = 0; i < (1 << n); i++) {
			for(int j = 1; j <= n; j++) {
				if(i & (1 << (j - 1))) candy[j].w = 2;
				else candy[j].w = 1;
			}
			for(int j = 1; j <= n; j++)
				candy[j].pl = (double)candy[j].a / candy[j].w;
			if(check()) ans++;
		}
		cout << ans << endl;
	}
}

int main() {
  freopen("sale.in", "r", stdin);
  freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(c == 18 || c == 16) {
			subA::main();
			continue;
		}
		if(c >= 1 && c <= 5) {
			baoli::main();
			continue;
		}
		cout << "Goodbye, OI" << endl;
	}
	return 0;
}
/*
 * luogu @xler0915
 * Goodbye, OI */
