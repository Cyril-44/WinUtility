#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
int minn = 1e18, sum = 0, ans = 0, pos = -1;
struct node {
	int x, y;
	bool operator< (const node& _) {
		return x < _.x;
	}
} a[100005];

int work(int money) {
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(money >= a[i].x) {
			money -= a[i].x;
			cnt++;
		}
	return cnt;
}

bool issubA() {
	for(int i = 1; i <= n; i++)
		if(a[i].x != a[i].y) return false;
	return true;
}
int subA() {
	int minn = 1e18;
	for(int i = 1; i <= n; i++)
		minn = min(minn, a[i].x);
	return m / minn;
}

signed main() {
  freopen("candy.in", "r", stdin);
  freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	if(issubA()) {
		cout << subA() << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		minn = min(minn, a[i].x + a[i].y);
	for(int i = 1; i <= n; i++)
		if(a[i].x + a[i].y == minn) {pos = i; break; }
	for(int i = 1; i <= pos; i++) 
		sum += a[i].x;
	for(int i = 0; ; i++) {
		if(m % minn + i * minn > 2 * sum) break;
		ans = max(ans, (m / minn - i) * 2 + work(m % minn + i * minn));		
	}
	cout << ans << endl;
	return 0;
}
/*
 * luogu @xler0915
 * Goodbye, OI */
