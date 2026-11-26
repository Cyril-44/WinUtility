#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long n, m, minid, s, ans;
struct node {
	long long x, y;
} a[N];

int cmp(node p, node q) {
	return p.x < q.x;
}

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + n + 1, cmp);
	minid = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].x + a[i].y <= a[minid].x + a[minid].y) {
			minid = i;
		}
	}
	ans = (m / (a[minid].x + a[minid].y)) * 2;
	for (int i = 1; i <= n; i++) {
		s += a[i].x;
		if (s <= m) {
			ans = max(ans, ((m - s) / (a[minid].x + a[minid].y)) * 2 + i);
		}
	}
	cout << ans << "\n";
	
	return 0;
}
