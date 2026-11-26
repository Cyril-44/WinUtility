#include <cstdio>

int read() {
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return f * x; 
}

#define MAXN 50000

long long fMax(long long a, long long b) {
	if (a > b) return a;
	else return b;
}

long long fMin(long long a, long long b) {
	if (a < b) return a;
	else return b;
}

int n, q;
long long s[MAXN + 10];
long long ll, rr, lenMax;
long long zaqqq[MAXN + 10];
unsigned long long ans = 0;

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; ++i) s[i] = read() + s[i - 1];
	q = read();
	while (q--) {
		ll = read(), rr = read(), lenMax = rr;
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			zaqqq[i] = -1000000000000000000;
			for (int j = fMax(1, i - lenMax + 1); j + lenMax - 1 <= n && j <= i; ++j) {
				zaqqq[i] = fMax(zaqqq[i], s[j + lenMax - 1] - s[j - 1]);
			}
			ans = ans ^ (i * zaqqq[i]);
		}
		printf("%llu\n", ans);
	}
	
	return 0;
}
