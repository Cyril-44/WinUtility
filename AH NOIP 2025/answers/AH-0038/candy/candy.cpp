#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
typedef long long LL;
const int N = 1e5+10;
LL m, mi, ans, sum, ans2, v;
int x[N], y[N], n, j, a[N];
int main() {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	mi = 0x3f3f3f3f;
	cin >> n >> m;
	rep(i, 1, n) {
		scanf("%d%d", &x[i], &y[i]);
		if (x[i]+y[i] < mi) {
			mi = x[i] + y[i];
		}
	}
	sort(x + 1, x + 1 + n);
	//rep(i, 1, 50)cout << x[i] << " ";
	//cout << endl;
	rep(i, 1, n) {
		if (x[i] + x[i-1] >= mi) {j = i-1; break;}
	}
	rep(i, 1, j-1) {
		if (sum + x[i] <= m) {
			ans++;
			sum += x[i];
		}
		else break;
	}
	LL k = ans;
	ans += (m-sum)/mi*2;
	if (sum + x[j] <= m) {
		sum += x[j];
		ans2 = max(ans, k + 1 + (m-sum)/mi*2);
	}
	cout << ans2;
	return  0;
}
