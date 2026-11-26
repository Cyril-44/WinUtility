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
using ull = unsigned long long;
constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

constexpr ll N = 50005;

ll n, q, arr[N], sum[N], L, R, ans[N];
ll getsum(ll l, ll r) {return sum[r] - sum[l - 1]; }

inline ll query_window(ll wsize, ll pos)
{
	ll lft = pos - wsize + 1, ret = LLONG_MIN;
	if(lft < 1) lft = 1;
	ll rgt = lft + wsize - 1, mxrgt = pos + wsize - 1;
	if(mxrgt > n) mxrgt = n; 
	while(rgt <= mxrgt)
	{
		ret = max(ret, getsum(lft, rgt));
		++lft; ++rgt;
	}
	return ret;
}

inline ll query_max(ll minl, ll maxr, ll pos)
{
	ll ret = LLONG_MIN;
	for(ll i = minl; i <= maxr; ++i)
		ret = max(ret, query_window(i, pos));
	return ret;
}

signed main()
{
	ifstream cin("query.in", ios::binary);
	ofstream cout("query.out", ios::binary);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i], sum[i] = sum[i - 1] + arr[i];
	cin >> q;
	while(q--)
	{
		cin >> L >> R;
		for(int i = 1; i <= n; ++i)
			ans[i] = query_max(L, R, i);
		ull ret = 0;
		for(int i = 1; i <= n; ++i)
			ret ^= i * ans[i];
		cout << ret << "\n";
	}
	
}

