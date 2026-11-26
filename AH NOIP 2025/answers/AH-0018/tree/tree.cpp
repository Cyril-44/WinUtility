#include <bits/stdc++.h>
using namespace std;
const int N = 7;
int T, n, a[N + 10], m;
bool vis[N + 3][N + 3];
vector <int> gra[N + 10];
int calc(int u) {
	int sum = 0;
	for(int i = 0; i < gra[u].size(); i++) {
		int v = gra[u][i];
		sum += calc(v);
		for(int j = 0; j < n; j++)
			vis[u][j] |= vis[v][j];
	}
	vis[u][a[u]] = 1;
	for(int i = 0; i <= n; i++)
		if(!vis[u][i]) {
			sum += i;
			break;
		}
	return sum;
}
int ans = 0;
void dfs(int u) {
	if(u > n) {
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < n; j++) vis[i][j] = 0;
		ans = max(ans, calc(1));
		return ;
	}
	for(int x = 0; x < n; x++) {
		a[u] = x;
		dfs(u + 1);
		a[u] = 0;
	}
}
void init() {
	cin >> n >> m;
	for(int i = 2, x; i <= n; i++)
		cin >> x, gra[x].push_back(i);

	ans = 0;
	dfs(1);
	cout << ans << '\n';
	for(int i = 1; i <= n; i++) gra[i].clear(), a[i] = 0;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) init(); 
}