#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10, inf = 1e14;
int n, m;
int ans;
struct node {
	int x, y, num;
	bool operator < (const node &W) const {
		return x < W.x;
	}
} c[N];
int minn = 1;
signed main(void) {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> c[i].x >> c[i].y, c[i].num = i;
	for (int i = 1; i <= n; i ++) {
		if(c[i].x + c[i].y < c[minn].x + c[minn].y || (c[i].x + c[i].y == c[minn].x + c[minn].y && c[i].x > c[minn].x)) minn = i;
	}
	//cout << c[minn].x << ' ' << c[minn].y << endl;
	int sum = c[minn].x + c[minn].y;
	int tx = c[minn].x, ty = c[minn].y;
	c[minn].x = c[minn].y = inf;
	sort(c + 1, c + n + 1);
	//for (int i = 1; i <= n; i ++) cout << c[i].x << ' ' << c[i].y << endl;
	//cout << endl << endl << endl;
	int pos = n;
	for (int i = 1; i + 1 < n; i += 2) {
		if(m < c[i].x) {
			pos = i;
			break ;
		}
		if(m < c[i].x + c[i + 1].x) {
			pos = i;
			break ;
		}
		if(c[i].x + c[i + 1].x >= sum) {
			pos = i;
			break ;
		}
		//cout << m << ' ';
		m -= c[i].x;
		m -= c[i + 1].x;
		//cout << m << endl;
		ans += 2;
	}
	int flag = 0;
	//cout << pos << endl;
	if(tx + c[pos].x < sum) {
        m -= (tx + c[pos].x);
        ans += 2;
        flag = 1;
	}
	//cout << flag << endl;
	ans += (m / sum * 2);
	m -= ((m / sum) * sum);
	if(!flag) {
        if(m >= min(tx, c[pos].x)) m -= min(tx, c[pos].x), ans ++;
        if(m >= max(tx, c[pos].x)) m -= max(tx, c[pos].x), ans ++;
	}
	else {
        if(m >= ty) ans ++, m -= ty;
	}
	if(c[pos - 1].x + m >= sum){
        ans ++;
	}
	cout << ans << endl;
	return 0;
}
