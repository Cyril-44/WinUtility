#include<algorithm>
#include<iostream>
#include<climits>
#define int long long
using namespace std;
const int N = 5e3 + 1, MOD = 998244353;
int c, t, n, m;
struct Price {
	int a, b, w;
} p[N];
signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++ i) {
			cin >> p[i].a;
			p[i].b = p[i].w = 0;
		}
	}
	
	return 0;
}
