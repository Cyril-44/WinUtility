#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
long long m;
long long ans = 0;
int cnt = 0;
int mn = 2 * 1e9;
int a[MAXN * 2];

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[++cnt] = x;
		mn = min(mn, x + y);
	}
	
	sort(a + 1, a + cnt + 1);
	long long sum = 0;
	for (int i = 1; i <= cnt; ++i) {
		sum += a[i];
		ans = max(ans, (m - sum) / mn * 2 + i);
	}
	cout << ans << endl;
}
