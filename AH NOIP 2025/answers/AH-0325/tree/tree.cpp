#include <bits/stdc++.h>
using namespace std;

const int N = 8005;
int n, m, ans;
vector<int> adj[N];

void work() {
	int ans = 0, maxson = 0;
	for(int i = 0; i < adj[1].size(); i++) {
		int u = adj[1][i];
		if(adj[u].size() == 0) {
			ans++;
			maxson = max(maxson, 1);
		} else {
			ans += adj[u].size() + 2;
			maxson = max(maxson, (int)adj[u].size() + 1);
		}
	}
	ans += maxson + 1;
	cout << ans << endl;
}

int main() {
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		for(int i = 2, f; i <= n; i++) {
			cin >> f;
			adj[f].push_back(i);
		}
		work();
	}
	return 0;
}
/*
 * luogu @xler0915
 * Goodbye, OI */
