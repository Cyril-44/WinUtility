#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
ll a[N + 10], b[N + 10], m;
int n;

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		a[i] = x + y, b[i] = x;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];

	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		if(b[i] > m) break;

		ll rem = m - b[i];
		ans = max(ans, (ll)i + 2ll * (rem / a[1]));
	}
	cout << ans << '\n';
}