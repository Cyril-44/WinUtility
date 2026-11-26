#include<algorithm>
#include<iostream>
#include<climits>
#define int long long
using namespace std;
const int N = 1e5 + 1;
int n, m, ans;
struct Candy {
	int x, y, sum;
} c[N], cc[N];
bool cmpa(Candy ta, Candy tb) {
	if(ta.sum != tb.sum) return ta.sum < tb.sum;
	else if(ta.x != tb.x) return ta.x < tb.x;
}
bool cmpb(Candy ta, Candy tb) {
	return ta.x < tb.x;
}
int get_ans() {
	int tans = LLONG_MIN;
	int k = m / c[1].sum * 2;
	for(int i = 0; i <= k; ++ i) {
		int tk = k - i, mm = m;
		if(i % 2 == 0) {
			mm = (mm % c[1].sum) + (i / 2) * (c[1].x + c[1].y);
			for(int j = 1; j <= n; ++ j) {
				if(mm >= cc[j].x) mm -= cc[j].x, ++ tk;
				else break;
			}
		}
		else if(i % 2 == 1) {
			mm = (mm % c[1].sum) + (i / 2) * c[1].x + (i / 2 + 1) * c[1].y;
			for(int j = 1; j <= n; ++ j) {
				if(cc[j].x == c[1].x && cc[j].y == c[1].y) continue;
				if(mm >= cc[j].x) mm -= cc[j].x, ++ tk;
				else break;
			}
		}
		tans = max(tans, tk);
	}
	return tans;
}
signed main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		cin >> c[i].x >> c[i].y;
		c[i].sum = c[i].x + c[i].y;
		cc[i].x = c[i].x, cc[i].y = c[i].y;
		cc[i].sum = c[i].sum;
	}
	sort(c + 1, c + n + 1, cmpa);
	sort(cc + 1, cc + n + 1, cmpb);
	cout << get_ans();
	return 0;
}
