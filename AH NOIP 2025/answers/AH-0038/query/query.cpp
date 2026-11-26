#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 1009;
int n, q, a[N], f[N], sum[N];
int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin >> n;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	cin >> q;
	if (q!=1) return 0;
	int L, R;
	cin >> L >> R;
	memset(f, 0x3f,sizeof(f));
	rep(i, 1, n) f[i] = -f[i];
	rep(i, 1, n) {
		rep(j, i+L-1, i+R-1) {
			if (j > n) break;
			int x = sum[j]- sum[i-1];
			rep(k, i, j) {
				f[k] = max(f[k], x);
			}
		}
	}
	unsigned long long ans;
	rep(i, 1, n) {
		ans ^= (unsigned long long)(i*f[i]);
	}
	cout << ans;
	return 0;
}
//AFO
