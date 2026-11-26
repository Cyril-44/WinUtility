#include <bits/stdc++.h>

#define ll int
#define in(x) scanf ("%d", &x)

using namespace std;

ll t;
ll n;
ll m;
ll l[1005];
ll h[10005];
ll fa[10005];
ll len[10005];
long long ans;
ll d[1005][1005];

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	in(t);
	while (t--) {
		in(n);
		in(m);
		fa[1] = 1;
		d[0][0] = 1;
		memset(l, 0, sizeof(l));
		for (ll i = 2; i <= n; i++) {
			in(fa[i]);
			len[fa[i]]++;
			h[i] = h[fa[i]] + 1;
			d[h[i]][++l[h[i]]] = i;
		}
		if (m == 1) {
			cout << n + 1 << endl;
			continue;
		}
		if (m == 2) {
			ll ans = 0;
			ll maxn = INT_MIN;
			for (ll i = 1; i <= l[1]; i++) {
				ans += len[d[1][i]] + 1;
				if (len[d[1][i]]) {
					ans++;
					maxn = max(maxn, len[d[1][i]] + 2);
				} else {
					maxn = max(maxn, len[d[1][i]] + 1);
				}
				//cout << maxn << endl;
			}
			ans += maxn;
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}

/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
