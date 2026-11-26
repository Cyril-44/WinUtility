#include<bits/stdc++.h>
using namespace std;


const long long N = 1e5 + 5;

struct c {
	long long x, y;
};

c candy[N];

bool cmp (c a, c b) {
	return a.x < b.x;
}

int main () {
	freopen ("candy.in", "r", stdin);
	freopen ("candy.out", "w", stdout);
	long long n, m, minm = LLONG_MAX, sum = 0, ans = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i) {
		cin >> candy[i].x >> candy[i].y;
		if (candy[i].x + candy[i].y < minm) minm = candy[i].x + candy[i].y;
	}
	sort (candy + 1, candy + 1 + n, cmp);
	for (long long i = 0; i <= n; ++i) {
		sum += candy[i].x;
		if (sum <= m) ans = max (ans, i + ((m - sum) / minm) * 2);
	}
	cout << ans << endl;
	return 0;
}
