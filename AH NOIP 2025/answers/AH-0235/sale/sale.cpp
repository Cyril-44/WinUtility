#include <fstream>
#include <iostream>

using namespace std;

constexpr int mod {998244353};

int main()
{
	ifstream cin("sale.in");
	ofstream cout("sale.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int c, t;
	for (cin >> c >> t; t--;)
	{
		int n, m, ans {1};
		cin >> n >> m;
		for (register int i {1}, a; i <= n; ++i)
		{
			cin >> a;
			ans = (ans << 1) % mod;
		}
		cout << ans << endl;
	}

	cin.close();
	cout.close();
	return 0;
}