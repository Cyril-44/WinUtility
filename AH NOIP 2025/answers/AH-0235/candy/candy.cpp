#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

array<int, 100001> x, y;

int main()
{
	ifstream cin("candy.in");
	ofstream cout("candy.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x_m {0x3f3f3f3f}, xy_m {0x3f3f3f3f};
	long long m;
	cin >> n >> m;
	for (register int i {1}; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
		if (x[i] < x_m)
			x_m = x[i];
		if (x[i] + y[i] < xy_m)
			xy_m = x[i] + y[i];
	}

	long long ans {m / xy_m * 2};
	m %= xy_m;
	if (m >= x_m)
	{
		sort(x.begin() + 1, x.begin() + n + 1);
		for (register int i {1}; m >= x[i] && i <= n; ++i)
		{
			++ans;
			m -= x[i];
		}
	}
	cout << ans << endl;

	cin.close();
	cout.close();
	return 0;
}