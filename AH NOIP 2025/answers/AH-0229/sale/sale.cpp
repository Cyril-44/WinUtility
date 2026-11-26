#include<bits/stdc++.h>
using namespace std;

const int N = 50005;
const long long p = 998244353;

int c, T, n, m;
int a[N];
long long ans;

struct node{
	int val, w, id;
}num2[N], num[N];

void in(int &x) {
	x = 0; int f = 1;
	char c = getchar();
	while (c < '0' && c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= f;
}

long long qpow(long long a, long long b){
	long long ret = 1;
	for (; b; b >>= 1) {
		if (b & 1) ret = (ret * a) % p;
		a = (a * a) % p;
	}
	return ret;
}

bool cmp(node a, node b) {
	if (a.val * b.w != b.val * a.w) return a.val * b.w > b.val * a.w;
	else if (a.val != b.val) return a.val > b.val;
	else return a.id < b.id;
}

long long s = 0;
void dfs2(int now, long long sum, int r) {
	if (now == n + 1) {
		s = max(s, sum);
		return;
	}
	if (r >= num[now].w) dfs2(now + 1, sum + num[now].val, r - num[now].w);
	dfs2(now + 1, sum, r);
}

bool work() {
	sort(num2 + 1, num2 + 1 + n, cmp);
	int r = m; long long sum = 0;
	for (int i = 1; i <= n; i ++) {
		if (num2[i].w <= r) {
			r -= num2[i].w;
			sum += num2[i].val;
		} 
		if (r == 0) break;
	}
	s = 0;
	dfs2(1, 0, m);
	return (s == sum);
}

void dfs(int now) {
	if (now == n + 1) {
		for (int i = 1; i <= n; i ++) {
			num2[i].w = num[i].w;
			num2[i].val = num[i].val;
		}
		if (work()) ans ++;
		return;
	}

	num[now].w = 1;
	dfs(now + 1);
	num[now].w = 2;
	dfs(now + 1);
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	in(c); in(T);
	while(T --) {
		ans = 0, s = 0;
		in(n); in(m);
		for (int i = 1; i <= n; i ++) {
			in(a[i]); num[i].val = a[i];
			num[i].id = i;
		}
		if (n <= 10) {
			dfs(1);
			printf("%lld\n", ans);
			continue;
		}
		sort(a + 1, a + 1 + n);
		if (m == 1) {
			printf("%lld\n", qpow(2ll, 1ll * n));
		} else if (m == 2) {
			if (n <= 2 || a[n] >= a[n - 1] + a[n - 2]) {printf("%lld\n", qpow(2, n)); continue;}
			int idx = 0;
			for (int i = n - 1; i > 1; i --) {
				if (a[i] + a[i - 1] <= a[n]) {idx = i; continue;}
			}
			int idd = idx;
			for (int i = 1; i <= idx; i ++) {
				if (a[i] > a[n] / 2){
					idd = i;
					continue;
				}
			}
			//cout << idd << ' ' << idx << endl;
			printf("%lld\n", qpow(2, n) - (qpow(2, idx - idd + 1) - 1));
		} else {
			printf("%lld\n", qpow(2ll, 1ll * n));
		}
	}
	return 0;
}
