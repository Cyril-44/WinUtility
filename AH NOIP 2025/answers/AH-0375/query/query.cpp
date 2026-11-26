#include <bits/stdc++.h>
using namespace std;
typedef long long ull;

int n, q;
long long a[100010], s[100010];

int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], s[i] = s[i - 1] + a[i];
	cin >> q;
	while(q --){
		unsigned long long ans = 0;
		int l, r;
		cin >> l >> r;
		for(int idx = 1; idx <= n; idx ++){
			ull maxn = -1e18;
			for(int len = l; len <= r; len ++)
				for(int l = max(1, idx - len + 1); l <= idx; l ++){
					int r = l + len - 1;
					ull now = s[r] - s[l - 1];
					maxn = max(maxn, now);
				}
			ans ^= maxn * idx;
		}
		cout << ans << '\n';
	}
	return 0;
}
//!noip@Nov29,2025:dream
