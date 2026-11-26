#include <bits/stdc++.h>

using namespace std;

const int N = 8e3 + 5;

int t, n, m, cnt, val[N], f, st, ans;
struct node {
	int u, p, dep, siz;
} a[N];

vector <int> G[N];
vector <int> lt[N];

void dfsdep(int u, int d) {
	a[u].dep = d;
	for (int i = 0; i < a[u].siz; i++) {
		dfsdep(G[u][i], d + 1);
	}
	return ;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			a[i].u = i, a[i].siz = 0, a[i].dep = 0, a[i].p = 0, val[i] = -1;
			G[i].clear();
		}
		for (int i = 0; i <= m; i++)	lt[i].clear();
		for (int i = 2; i <= n; i++) {
			cin >> a[i].p;
			G[a[i].p].push_back(i);
			a[a[i].p].siz++;
		}
		dfsdep(1, 0);
		st = 0;
		for (int i = 1; i <= n; i++) {
			lt[a[i].dep].push_back(i);
			val[i] = -1;
		}
		for (int i = m; i >= 0; i--) {
			if (lt[i].size()) {
				st = i;
				val[lt[i][0]] = 0;
				break;
			}
		}
		cnt = 1, f = 0, ans = 0;
		for (int i = st; i >= 0; i--) {
			for (int j = 0; j < lt[i].size(); j++) {
				if (val[lt[i][j]] != -1)	f = j, ans += val[lt[i][j]] + 1;
				if (val[lt[i][j]] == -1)	val[lt[i][j]] = cnt, cnt++;
			}
			if (i > 0)	val[lt[i - 1][a[f].p]] = cnt, cnt++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
