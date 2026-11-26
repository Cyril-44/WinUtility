#include <queue>
#include <utility>
#include <vector>
#include <cstdint>
#include <cstring>
#include <cstddef>
#include <climits>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

constexpr ll N = 50005;
ll c, t, n, m, arr[N], dp[105][105], w[N], ans;
struct nd{ ll a, w, id; }cpy[N];
inline ll max_buy()
{
	memset(dp, 0, sizeof(dp));
	for(ll i = 1; i <= n; ++i)
		for(ll j = 0; j <= m; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if(j >= w[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + arr[i]);
		}
	ll mx = 0;
	for(ll i = 1; i <= n; ++i)
		for(ll j = 0; j <= m; ++j)
			mx = max(mx, dp[i][j]);
	return mx;
}
inline ll way_buy()
{
	for(int i = 1; i <= n; ++i)
		cpy[i].a = arr[i], cpy[i].w = w[i], cpy[i].id = i;
	sort(cpy + 1, cpy + 1 + n, [](nd& l, nd& r){
		if(l.a * r.w == l.w * r.a)
			if(l.a == r.a)
				return l.id < r.id;
			else
				return l.a > r.a;
		else
			return l.a * r.w > l.w * r.a;
		});
	ll less = m, cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(less >= cpy[i].w)
			less -= cpy[i].w, cnt += cpy[i].a;
	}
	return cnt;
}
inline void dfs(int cur)
{
	if(cur > n)
	{
		ll wgt1 = max_buy();
		ll wgt2 = way_buy();
		ans += wgt1 == wgt2;
		return;
	}
	w[cur] = 1;
	dfs(cur + 1);
	w[cur] = 2;
	dfs(cur + 1);
}
signed main()
{
	ifstream cin("sale.in", ios::binary);
	ofstream cout("sale.out", ios::binary);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			cin >> arr[i];
		ans = 0;
		dfs(1);
		cout << ans << "\n";
	}
}


