#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

typedef long long LL;

int n;
LL m;
struct node
{
	LL x, y;
} a[N];

bool cmp(node p, node q)
{
	return p.x < q.x;
}

int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++ )
	{
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}
	LL kx = a[1].x, ky = a[1].y;
	for (int i = 1; i <= n; i ++ )
	{
		if(a[i].x + a[i].y < kx + ky)
		{
			kx = a[i].x, ky = a[i].y;
		}
		else if(a[i].x + a[i].y == kx + ky && a[i].x < kx)
		{
			kx = a[i].x, ky = a[i].y;
		}
	}
	
	sort(a + 1, a + n + 1, cmp);
	LL sum = 0, ans = 0;
	for (int i = 1; i <= n + 1; i ++ )
	{
		LL t = (m - sum) / (kx + ky); LL tmp = t * 2;
		if(m - sum - (kx + ky) * t >= kx) tmp ++;
		ans = max(ans, tmp + i - 1);
		if(i > n) break;
		sum += a[i].x;
	}
	printf("%lld\n", ans);
	
	return 0;
}
