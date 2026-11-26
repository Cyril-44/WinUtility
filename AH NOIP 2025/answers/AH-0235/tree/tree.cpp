#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream cin("tree.in");
	ofstream cout("tree.out");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	for (cin >> t; t--;)
	{
		int n, m;
		cin >> n >> m;
		for (register int i {2}, p; i <= n; ++i)
			cin >> p;
		cout << n * m << endl;
	}

	cin.close();
	cout.close();
	return 0;
}