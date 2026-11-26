#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 5009;
typedef long long LL;
struct candy{
	int a, w;
}a[N],b[N];
int c, t, n, m;
bool cmp(const candy &x, const candy &y) {
	if (x.a*1.0/(x.w*1.0) == y.a*1.0/(y.w*1.0)) return x.a > y.a;
	return x.a*1.0/(x.w*1.0) > y.a*1.0/(y.w*1.0);
}
int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i].a);
		LL ans = 0;
		rep(i, 0, (1<<n)-1) {
			rep(j, 1, n) {
				b[j].a = a[j].a;
				if ((i >> (j-1))&1) b[j].w = 2;
				else b[j].w = 1;
			}
			sort(b + 1, b + 1 + n, cmp);
			int sum = 0, flag = 0;
			rep(i, 1, n) {
				if (b[i].w + sum <= m) sum += b[i].w;
				else if (b[i].w == 2 && sum != m) {
					int x = 0, y = 0;
					per(j, i, 1) {
						if (b[j].w == 1) {
							x = b[j].a;
							break;
						}
					}
					rep(j, i, n) {
						if (b[j].w == 1) {
							y = b[j].a;
							break;
						}
					}
					if (x!=0 && x+y < b[i].a) flag = 1;
					break;
				}
				else break;
			}
			if (!flag) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
