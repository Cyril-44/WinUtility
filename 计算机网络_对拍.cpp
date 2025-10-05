#include <bits/stdc++.h>
#include <random>
#include <Windows.h>
using namespace std;
const int N = 200005;
vector<int> g[N];
int f[N][2], h[N];
mt19937 rng(time(0));
inline int rdint(int l, int r) {
	unsigned tmp = rng();
	return l + tmp % (r - l + 1);
}
inline int rd(int n) {
	return rng() % n;
}
bool vis[N];
int a[N];
void dfs(int u) {
	int cnt = min(rdint(1, 10), a[0]);
	std::vector<int> c;
	for (int i = 0; i < cnt; i++) {
		int tp = rdint(1, a[0]);
		c.push_back(a[tp]);
		swap(a[tp], a[a[0]--]);
		printf("%d %d\n", u, c[i]);
	}
	for (int i = 0; i < cnt; i++) {
		dfs(c[i]);
	}
}
int main() {
	bool flg = true;
	while (flg) {
		freopen("B.in", "wt", stdout);
		int n = rdint(10, 20);
		printf("%d\n", n);
		a[0] = n-1;
		for (int i = 1; i <= n; i++) a[i] = i;
		random_shuffle(a+1,a+1+n, rd);
		int u = rdint(1, n);
		swap(a[u], a[n]);
		dfs(a[n]);
		fclose(stdout);
		if (system("B.exe")) {
			fputs("Get.", stderr);
			return 1;
		}
		else {
			fprintf(stderr, "Failed: n=%d\n", n);
		}
	}
	return 0;
}