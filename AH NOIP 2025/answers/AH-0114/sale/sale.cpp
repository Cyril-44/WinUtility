#include <cstdio>
#include <algorithm>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x;
}

#define MAXN 5000
#define fMax(a, b) (((a) > (b)) ? (a) : (b))

struct node {
	friend bool operator < (const node &a, const node &b) {
		if (b.v * a.w == a.v * b.w) return a.v > b.v;
		return a.v * b.w > a.w * b.v;
	}

	long long v, w;
};

int c, t;
int n, m;
node a[MAXN + 10];
long long maxVal = -1;
long long ans;

long long getMaxVal() {
	long long dp[50][100];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j] = 0;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (j >= a[i].w) dp[i][j] = fMax(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].v);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][m];
}

void dfs(int idx) {
	if (idx == n + 1) {
		long long total = 0;
		int mm = m;
		node b[n + 10];
		for (int i = 1; i <= n; ++i) b[i] = a[i];
		sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n; ++i) {
			if (mm >= b[i].w) {
				mm -= b[i].w;
				total += b[i].v;
			}
		}
		maxVal = getMaxVal();
		if (total == maxVal) ++ans;
		return;
	}
	a[idx].w = 1;
	dfs(idx + 1);
	a[idx].w = 2;
	dfs(idx + 1);
	return;
}

void solve1() {
	ans = 0;
	dfs(1);
	return;
}

int main() {

	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);

	c = read(), t = read();
	while (t--) {
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) a[i].v = read();
		if (n <= 40) {
			solve1();
			printf("%lld\n", ans);
		}
	}
	return 0;
}
