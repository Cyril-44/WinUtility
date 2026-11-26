#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int p[8001], son[8001], maxs = 0, ans = 0;
		for(int j = 0; j <= 8000; j++) son[j] = p[j] = 0;
		cin >> n >> m;
		for(int j = 2; j <= n; j++) {
			cin >> p[j];
			if(p[j] != 1) {son[p[j]]++; if(son[p[j]] > son[maxs]) maxs = p[j];}
		}
		ans += (n - 2 - son[maxs]);
		for(int j = 1; j <= son[p[j]] + 2; j++) ans += j;
		cout << ans << endl;
	}
	return 0;
}
