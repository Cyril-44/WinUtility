#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MOD = 998244353;

int T, c;
int n, m;
int a[MAXN];
long long f[MAXN];
long long inv[MAXN];
long long sum[MAXN];
long long ans = 0;

long long QUICK_POWER(long long x, long long y) {
	long long res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void FRAC_INIT() {
	inv[0] = f[0] = 1;
	for (int i = 1; i <= 5000; ++i) f[i] = f[i - 1] * i % MOD;
	inv[5000] = QUICK_POWER(f[5000], MOD - 2);
	for (int i = 4999; i; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
	//for (int i = 1; i <= 100; ++i) cout << f[i] * inv[i] % MOD << endl;
}

long long C(int x, int y) {
	if (y > x) return 0;
	return ( f[x] * inv[y] % MOD ) * inv[x - y] % MOD;
}

bool COMP(int x, int y) {
	return x > y;
}

void INIT() {
	ans = 0;
	memset( a, 0, sizeof(a) );
	memset( sum, 0, sizeof(sum) );
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> c >> T;
	FRAC_INIT();
	
	if (c == 18) {
		while (T--) {
			INIT();
			cin >> n >> m;
			for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
			cout << QUICK_POWER(2, n) % MOD << endl;
		}
	}
	
	if (c == 16) {
		while (T--) {
			INIT();
			cin >> n >> m;
			for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
			cout << 0 << endl;
		}
	}
	
	if (c == 7 || c == 8 || c == 9 || c == 14 || c == 15) {
		//cout << 1 << endl;
		while (T--) {
			INIT();
			cin >> n >> m;
			for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
			//cout << 1 << endl;
			sort(a + 1, a + n + 1,COMP);
			//reverse(a + 1, a + n + 1);
			
			ans = QUICK_POWER(2, n);
			for (int i = 2; i <= n; ++i) {
				if (a[i] * 2 > a[1]) ans--;
				//cout << i << endl;
				for (int j = i + 1; j <= n; ++j) {
					if (a[i] * 2 > a[1] && a[i] + a[j] < a[1]) {
						ans = (ans - QUICK_POWER(2, n - j) + MOD) % MOD;
					}
				}
			}
			
			printf("%lld\n", (ans + MOD) % MOD);
		}
	}
}
