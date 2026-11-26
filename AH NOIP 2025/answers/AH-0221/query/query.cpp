#include <bits/stdc++.h>
using namespace std;
int n,q,a[500005];
long long sum[500005],k[500005];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	cin >> q;
	while(q--)
	{
		int l,r,op = 0;
		cin >> l >> r;
		for(int i = 1; i <= n; i++)
		{
			long long maxx = -1e18;
			for(int j = l; j <= r; j++)
			{
				if(i + j - 1 > n)
				{
					for(int k = max(1,i - j + 1); k <= n - j + 1; k++)
					{
						maxx = max(maxx,sum[k + j - 1] - sum[k - 1]);
					}
				}
				else
				{
					for(int k = max(1,i - j + 1); k <= i; k++)
					{
						maxx = max(maxx,sum[k + j - 1] - sum[k - 1]);
					}
				}
			}
			k[++op] = maxx;
		}
		long long endans = k[1];
		for(int i = 2; i <= op; i++)
		{
			endans = endans ^ (i * k[i]);
		}
		cout << endans << "\n";
	}
	return 0;
}
