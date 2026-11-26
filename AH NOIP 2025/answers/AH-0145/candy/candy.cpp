#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, m, a[N], b[N], ans;
vector<int>ar;

signed main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	int Min = 2e9, id;
	for (int i = 1; i <= n; ++i)
		if (Min > a[i] + b[i]) Min = a[i] + b[i], id = i;
	for (int i = 1; i <= n; ++i)
		if (i != id) ar.push_back(a[i]);
	sort(ar.begin(), ar.end());
	int st = -1;
	for (int i = 0; i < (int)ar.size(); i += 2) {
		if (i == (int)ar.size() - 1) st = i;
		else if (ar[i] + ar[i + 1] < Min) {
			if (m >= ar[i] + ar[i + 1]) ans += 2, m -= ar[i] + ar[i + 1];
			else {
				st = i;
				break;
			}
		}
		else {
			st = i;
			break;
		}
	}
	ans += (m / Min) * 2;
	m %= Min;
	bool f = 0;
	for (int i = st; i < (int)ar.size(); ++i) 
		if (f) {
			if (m >= ar[i]) ++ans, m -= ar[i];
			else break;
		}
		else {
			if (ar[i] > a[id]) {
				f = 1;
				if (m >= a[id]) m -= a[id], ++ans;
				else break;
			}
			else {
				if (m >= ar[i]) ++ans, m -= ar[i];
				else break;
			}
		}
	if (!f && a[id] <= m) ++ans;
	cout << ans << "\n";
	
	return 0;
}
