#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5010, mod = 998244353;

typedef long long LL;
typedef pair<LL, LL> PII;

int T, c, n, m;
int a[N];
LL mul[N], inf[N];
LL f[110][110];
struct node
{
	LL x, y;
} b[N];

LL quick_pow(LL a, int b)
{
	LL res = 1;
	while (b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

bool cmp(node p, node q)
{ 
	if(p.x * q.y != q.x * p.y) return p.x * q.y > q.x * p.y;
	else return p.x > q.x;
}

int check(int st)
{
	for (int i = 1; i <= n; i ++ )
	{
		if(st >> (i - 1) & 1) b[i].y = 2;
		else b[i].y = 1;
		b[i].x = a[i];
	}
	sort(b + 1, b + n + 1, cmp);
	
	int t = m; LL ans1 = 0;
	for (int i = 1; i <= n; i ++ )
		if(b[i].y <= t) t -= b[i].y, ans1 += b[i].x;
		
	for (int i = 0; i <= n; i ++ )
		for (int j = 0; j <= m; j ++ )
			f[i][j] = 0;
		
	LL ans2 = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j <= m; j ++ )
		{
			if(b[i].y <= j) f[i][j] = max(f[i - 1][j], f[i - 1][j - b[i].y] + b[i].x);
			ans2 = max(ans2, f[i][j]);
		}
	return (ans1 == ans2);
}

LL C(LL n, LL m)
{
	return mul[n] * inf[n - m] % mod * inf[m] % mod;
}

int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	
	mul[0] = 1;
	for (int i = 1; i < N; i ++ ) mul[i] = mul[i - 1] * i % mod;
	for (int i = 0; i < N; i ++ ) inf[i] = quick_pow(mul[i], mod - 2);

	scanf("%d%d", &c, &T);
	while (T -- )
	{
		scanf("%d%d", &n, &m); bool A = 1, B = 1; 
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%d", &a[i]);
			if(a[i] <= 5e8) B = 0;
		}
		for (int i = 2; i <= n; i ++ ) if(a[i] != a[i - 1]) A = 0;
		if(A || m == 2 * n - 1)
		{
			printf("%lld\n", quick_pow(2ll, n));
			continue;
		}
		else if(m == 2)
		{
			sort(a + 1, a + n + 1);
			LL res = quick_pow(2, n);
			
			for (int j = n - 1; j >= 1; j -- )
			{
				if(a[j] * 2 > a[n]) // a[j] > a[n] / 2
				{
					int k = lower_bound(a + 1, a + j, a[n] - a[j]) - a - 1;
					if(a[1] + a[j] >= a[n]) k = 0;
					if(a[j - 1] + a[j] < a[n]) k = j - 1;
					res = (res - quick_pow(2, k) + mod) % mod;
				}
				else break;
			}
			printf("%lld\n", res);
			continue;
		}
		else if(B)
		{
			sort(a + 1, a + n + 1);
			if(m % 2 == 0)
			{
				LL res = quick_pow(2ll, n);
				for (int k = 0; k <= min(m - 2, n - 1); k += 2 )
				{
					if((m - k) / 2 + k >= n) break;
					LL tmp = C((m - k) / 2 + k, k) * (n - (m - k) / 2 - k) % mod;
					res = (res - tmp + mod) % mod;
				}
				printf("%lld\n", res);
			}
			
			continue;
		}
		else if(n <= 10)
		{
			int ans = 0;
			for (int st = 0; st < (1 << n); st ++ )
			{
				ans += check(st);
			}
			printf("%d\n", ans);
			continue;
		}
		else if(m == 2 * n - 2)
		{
			sort(a + 1, a + n + 1);
			LL res = quick_pow(2ll, n);
			for (int i = 1; i < n; i ++ )
			{
				int j = upper_bound(a + 1, a + n + 1, a[i]) - a;
				if(a[i] * 2 > a[j]) res = (res - 1 + mod) % mod;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
