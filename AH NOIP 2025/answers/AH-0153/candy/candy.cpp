#include <queue>
#include <utility>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

constexpr ll N = 100005;
ll n, m;
struct nd{ ll x, y; } arr[N];

namespace s1
{
	ll dp[1005][10005];
	inline ll wgt(ll ith, ll num)
	{
		ll a = num / 2, b = num % 2;
		if(b == 0)
			return (arr[ith].x + arr[ith].y) * a;
		else
			return (arr[ith].x + arr[ith].y) * a + arr[ith].x;

	}
	inline ll work()
	{
		sort(arr + 1, arr + 1 + n, [](nd& l, nd &r) {return l.x + l.y < r.x + r.y; });
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= m; ++j)
				for(int k = 0; j + wgt(i, k) <= m ; ++k)
				{
					ll nval = dp[i - 1][j] + k;
					if(dp[i][j + wgt(i, k)] < nval)
						dp[i][j + wgt(i, k)] = nval;
					//dp[i][j + wgt(i, k)] = max(dp[i][j + wgt(i, k)],
						//dp[i - 1][j] + k);
				}
		ll mx = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j <= m; ++j)
			{
				if(dp[i][j] > mx)
					mx = dp[i][j];
			}
		return mx;
	}
}
namespace s2
{
	struct dt
	{
		ll val, id, ptr;
		friend bool operator > (const dt& l, const dt& r)
		{
			return l.val > r.val;
		}
	};

	inline ll work()
	{
		sort(arr + 1, arr + 1 + n, [](nd& l, nd &r) {return l.x + l.y < r.x + r.y; });
		ll ans = m / (arr[1].x + arr[1].y),
		   less = m - ans * (arr[1].x + arr[1].y);
		ans *= 2;
		if(less == 0)
			return ans;
		priority_queue<dt, vector<dt>, greater<dt>> tmp;
		for(int i = 1; i <= n; ++i)
			tmp.push(dt{arr[i].x, 1, i});
		while(true)
		{
			dt sl = tmp.top();
			ll ptr = sl.ptr;
			tmp.pop();			
			if(less - sl.val < 0)
				break;
			less -= sl.val; ++ans;
			if(sl.id == 1)
				tmp.push(dt{arr[ptr].y, 2, ptr});
			else
				tmp.push(dt{arr[ptr].x, 1, ptr});
		}
		return ans;
	}	
}
signed main()
{
	ifstream cin("candy.in", ios::binary);
	ofstream cout("candy.out", ios::binary);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i].x >> arr[i].y;
	if(n <= 1000 || m <= 10000)
		cout << s1::work();
	else
		cout << s2::work();
}

