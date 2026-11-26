#include<iostream>
#include<limits.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
long long n, q, L, R, a[100001], pre[100001];
long long max_value, value;
int lBound, rBound;
unsigned long long ans = 0;
unordered_map<long long, long long> table[100001];
#define V(L, R) (pre[R] - pre[L - 1])
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	cin >> q;
	while(q--)
	{
		ans = 0;
		cin >> L >> R;
		for(long long i = 1; i <= n; i++)
		{
			max_value = LLONG_MIN;
			for(long long len = L, max_value_temp; len <= R; len++)
			{
				if(table[i][len])
					max_value_temp = table[i][len];
				else
				{
					max_value_temp = LLONG_MIN;
					lBound = max(1ll, i - len + 1), rBound = min(i, n - len + 1);
					for(long long j = lBound; j <= rBound; j++)
						max_value_temp = max(max_value_temp, V(j, j + len - 1));
					table[i][len] = max_value_temp;
				}
				max_value = max(max_value, max_value_temp);
			}
			ans ^= i * max_value;
		}
		cout << ans << "\n";
	}
	return 0;
}
