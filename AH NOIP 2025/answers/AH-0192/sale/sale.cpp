#include<iostream>
#include<algorithm>
using namespace std;
int c, t, n, m, a[5001];
bool flag;
unsigned long long dp[5001][2];
const unsigned long long MOD = 9982443563ull;
void greedy()
{
	unsigned long long ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans <<= 1;
		if(ans > MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		flag = true;
		for(int i = 1; i < n; i++)
			flag &= (a[i] == a[i + 1]);
		if(flag){greedy();continue;}
		dp[1][0] = dp[1][1] = 1ull;
		for(int i = 2; i <= n; i++)
		{
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			if((a[i - 1] << 1) <= a[i])
				dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
			else
				dp[i][1] = dp[i - 1][1];
		}
		cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
	}
	return 0;
}
