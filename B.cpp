#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using std::max;
using std::min;
const int N = 200005;
std::vector<int> g[N];
int f[N][2], h[N];
void dfs(int u, const int& fa) {
	for (const int &v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		int len = f[v][0] + 1;
		if (len > f[u][0])
			f[u][1] = f[u][0], f[u][0] = len;
		else if (len > f[u][1])
			f[u][1] = len;
	}
}
void dfs2(int u, const int &fa) {
	int tmp = f[u][0] + 1;
	if (tmp == f[fa][0]) {
		if (f[fa][1]) tmp = f[fa][1] + 1;
		else tmp = 0;
	}
	else tmp = f[fa][0] + 1;
	h[u] = max(h[fa] + 1, tmp);
	for (const int &v : g[u]) {
		if (v ^ fa)	dfs2(v, u);
	}
}
using mkp = std::pair<int,int>;
inline std::vector<int> bfs(const int &n) {
	std::queue<std::pair<int,int>> q;
	static bool vis[N];
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++)
		if (g[i].size() == 1)
			q.push(mkp(i, 1)), vis[i] = true;
	int mx = 0;
	std::vector<int> ans;
	while (!q.empty()) {
		mkp u = q.front();
		q.pop();
		if (u.second > mx) {
			mx = u.second;
			ans.clear();
		}
		if (u.second == mx) ans.push_back(u.first);
		for (int v : g[u.first]) {
			if (vis[v]) continue;
			q.push(mkp(v, u.second+1));
			vis[v] = true;
		}
	}
	return ans;
}
int main() {
	freopen("B.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs(1, 0);
	f[0][0] = h[0] = -1; dfs2(1, 0);
	int mn = n;
	std::vector<int> a1;
	for (int i = 1; i <= n; i++) {
		// debug("(%d,%d,%d)", h[i], f[i][0], f[i][1]);
		h[i] = max(h[i], f[i][0]);
		mn = min(mn, h[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (h[i] == mn)
			a1.push_back(i);
	}
	std::vector<int> a2 = bfs(n);
	if (a1 != a2) {
		for (int i : a1) debug("%d ", i);
		debug("\n");
		for (int i : a2) debug("%d ", i);
		debug("\n");
		return 1;
	}
	return 0;
}
