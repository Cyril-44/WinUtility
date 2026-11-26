#include<bits/stdc++.h>
using namespace std;


const long long N = 105;

vector <long long> road[N];

long long p[N], fil[N], str[N][N], col[N], n, tans;

long long dfs2 (long long x) {
	long long ans = 0;
	for (long long i = 0; i < n; ++i) str[x][i] = 0;
	str[x][fil[x]] = 1;
	for (auto i : road[x]) {
		ans += dfs2 (i);
		for (long long j = 0; j < n; ++j) str[x][j] |= str[i][j];
	}
	for (long long i = 0; i < n; ++i) {
		if (str[x][i] == 0) {
			ans += i;
			break;
		}
	}
	return ans;
}

void dfs (long long dep) {
	if (dep == n + 1) {
		if (dfs2 (1) > tans) {
			tans = dfs2 (1);
			for (int i = 1; i <= n; ++i) col[i] = fil[i];
		}
		return ;
	}
	for (long long i = 0; i < n; ++i) fil[dep] = i, dfs (dep + 1);
}

int main () {
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);
	long long t, m;
	cin >> t;
	while (t--) {
		cin >> n >> m, tans = 0;
		for (long long i = 1; i <= n; ++i) road[i].clear ();
		for (long long i = 2; i <= n; ++i) cin >> p[i], road[p[i]].push_back (i);
		if (n <= 7) {
			dfs (1), cout << tans << endl;
			for (int i = 1; i <= n; ++i) cout << col[i] << " ";
			cout << endl;
			continue;
		}
	}
	return 0;
}
