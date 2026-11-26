#include <cstdio>
#include <algorithm>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x;
}

#define MAXN 100000

int n;
long long m;
long long a[MAXN + 10];
long long mina = 2000000000;
long long ans;

long long f(int i, long long s) {
	long long tmp = (m - s) / mina;
	return i + tmp * 2;
}

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	n = read();
	scanf("%lld", &m);
	for (int i = 1, tmp; i <= n; ++i) {
		a[i] = read(), tmp = read();
		tmp += a[i];
		if (tmp < mina) mina = tmp;
	}
	
	sort(a + 1, a + 1 + n);
	long long s = 0, tmp;
	for (int i = 0; i <= n && a[i] <= mina; ++i) {
		s += a[i];
		tmp = f(i, s);
		if (tmp > ans) ans = tmp;
	}
	printf("%lld\n", ans);
	
	return 0;
}
