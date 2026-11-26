#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long n;
long long m;

struct node{
	long long x, y;
}a[N];

bool cmp(node a, node b) {
	return a.x < b.x;
}

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	long long mn = 0, mnx, mny;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].x >> a[i].y;
		if (mn == 0) mn = a[i].x + a[i].y, mnx = a[i].x, mny = a[i].y;
		else if (mn > a[i].x + a[i].y) {
			mn = a[i].x + a[i].y;
			mnx = a[i].x, mny = a[i].y;
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	long long ans = 2 * (m / mn); long long r = m - ans / 2 * mn;
	//cout << ans << ' ' << r << endl;
	int ok = 1;
	for (int i = 1; i <= n; i ++) {
		int tmp = (ok ? mny : mnx); ok = 1 - ok;
		if (r >= a[i].x) ans ++, r -= a[i].x;
		else if (tmp > a[i].x) r += (tmp - a[i].x);
		else break;
	}
	cout << ans << endl;
	return 0;
}
