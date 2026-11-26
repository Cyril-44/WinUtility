#include <bits/stdc++.h>

#define ll long long
#define in(x) scanf ("%lld", &x)

using namespace std;

ll n;
ll m;
ll ans;
ll s[100005];

struct node {
	ll x;
	ll y;
	ll z;
	bool f;
};

struct node2 {
	ll val;
	ll id;
};

node a[100005];
node2 k[100005];

bool cmp(node qwq, node pwp) {
	if (qwq.z == pwp.z) {
		return qwq.y < pwp.y;
	}
	return qwq.z < pwp.z;
}

bool cmp2(node2 qwq, node2 pwp) {
	return qwq.val < pwp.val;
}

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	in(n);
	in(m);
	for (ll i = 1; i <= n; i++) {
		in(a[i].x);
		k[i].val = a[i].x;
		k[i].id = i;
		in(a[i].y);
		a[i].z = a[i].x + a[i].y;
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(k + 1, k + 1 + n, cmp2);
	a[1].f = 1;
	ll tt = 1;
	for (ll i = 2; i <= n; i++) {
		if (a[i].z == a[1].z) {
			tt = i;
		}
	}
//	for (ll i = 1; i <= n; i++) {
//		cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
//	}
	ans = (m / a[1].z) * 2ll;
	m %= a[1].z;
	if (n == 1) {
		if (m >= k[1].val) {
			ans++;
		}
		cout << ans << endl;
		return 0;
	}
	if (n == 2) {
		if (m >= k[1].val) {
			ans++;
			m -= k[1].val;
		}
		if (m >= k[2].val) {
			ans++;
		}
		cout << ans << endl;
		return 0;
	}
//	cout << m << endl;
	for (ll i = 1; i <= n; i++) {
		s[i] = s[i - 1] + k[i].val;
	}
//	for (ll i = 1; i <= n; i++) {
//		cout << s[i] << endl;
//	}
	ll cnt = 1;
	while (s[cnt] <= m && cnt <= n) {
		cnt++;
	}
	ans += cnt - 1;
//	cout << ans << endl;
//	cout << cnt << endl;
	ll sum = ans;
	ll txt = ans;
	ll ii = tt;
	ll jj = 1;
	while (1) {
		if (a[ii].y < a[jj].x && a[jj].f) {
			m += a[jj].x;
			sum--;
			a[jj].f = 0;
		} else {
			if (a[ii].y < a[jj].x) {
				jj++;
				jj %= tt;
				if (jj == 0) {
					jj = tt;
				}
			}
			m += a[ii].y;
			a[ii].f = 1;
			ii--;
			ii %= tt;
			ii += tt;
			ii %= tt;
			if (ii == 0) {
				ii = tt;
			}
			sum--;
		}
		//cout << m << endl;
		ll ss = 0;
		while (s[cnt] <= m && cnt <= n) {
			cnt++;
			ss++;
		}
		sum += ss;
		txt = sum;
		//cout << ss << endl;
		if (s[cnt + 2] - s[cnt] >= a[1].z && cnt + 2 <= n) {
			break;
		}
		if (cnt + 2 > n) {
			break;
		}
	}
	ans = max(ans, max(txt, sum));
	cout << ans << endl;
	return 0;
}


/*
2 10
4 1
3 3

3 15
1 7
2 3
3 1

*/
