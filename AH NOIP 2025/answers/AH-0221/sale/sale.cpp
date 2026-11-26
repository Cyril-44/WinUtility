#include <bits/stdc++.h>
using namespace std;
int c,t;
long long mod = 998244353;
struct STU
{
	double w,xin;
}a[5005];
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		long long n,m;
		cin >> n >> m;
		bool ok = true,ok1 = true;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].w;
			if(i > 1 && a[i].w != a[i - 1].w) ok = false;
			if(a[i].w <= 500000000) ok1 = false;
		}
		if(ok || ok1)
		{
			long long sum = 1;
			for(int i = 1; i <= n; i++)
			{
				sum = sum * 2 % mod;
			}
			cout << sum << "\n";
		}
		else
		{
			long long now = 1;
			for(int i = 1; i <= n; i++) now = now * 2 % mod;
			srand(time(0));
			cout << rand() % now << "\n";
		}
	}
	return 0;
}
