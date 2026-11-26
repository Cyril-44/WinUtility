#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 8009;
int n, m, t, fa[N], f[N], vis[N], ans, cnt, siz[N];
vector<int> g[N];
void dfs(int x) {
	vis[f[x]] = 1;
	for(auto y:g[x]) {
		dfs(y);
	}
}
int check() {
	cnt = 0;
	rep(i, 1, n) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
		rep(j, 0, n-1) {
			if (!vis[j]) {
				cnt += j;
				break;
			}
		}
	}
	return cnt;
}
void Dfs(int x) {
	//cout << x << endl;
	if (x == n+1) {
		int tmp = check();
		if (tmp > ans) ans = tmp;
		return ;
	}
	rep(i, 0, n-1) {
		f[x] = i;
		Dfs(x+1);
	}
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> t;
	while(t--) {
		scanf("%d%d", &n, &m);
		memset(siz,0,sizeof(siz));
		ans = 0;
		rep(i, 1, n) g[i].clear();
		rep(i, 2, n) {
			scanf("%d", &fa[i]);
			g[fa[i]].push_back(i);
			siz[fa[i]]++;
		}
		if (m == n-1) {
			cout << (n+1)*n/2 << endl;
			continue;
		}
		if (m > 2 || n < 7) Dfs(1);
		else if (m==2){
			int ma = 0;
			//rep(i, 1, n) cout << siz[i] << endl;
			rep(i, 2, n) {
				if (fa[i] == 1) {
					ans += siz[i]+1;
					if (siz[i]) ans++;
					ma = max(ma, siz[i]);
				}
			}
			//cout << ma << endl;
			ans += ma+2;
		}
		else if (m == 1) ans = n+1;
		printf("%d\n", ans);
	}
	return 0;
}
