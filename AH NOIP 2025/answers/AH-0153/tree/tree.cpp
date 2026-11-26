#include <set>
#include <vector>
#include <cmath>
#include <iterator>
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

constexpr ll N = 8005;
set<ll> s[N];
ll t, n, m, fa[N], ans, w[N], time_stamp;
vector<ll> child[N];
template<typename T>
inline void set_merge(set<T>& s1, set<T>& s2)
{
	for(const auto& x : s2)
		s1.insert(x);
}
template<typename T>
inline T mex(set<T>& s) //O(n)
{
	if(*s.begin() != 0) return 0;
	if(s.size() == 1) return 1; //begin = 0
	auto it1 = s.begin(), it2 = next(it1);
	while(it2 != s.end())
		if(*it2 - *it1 != 1)
			return *it1 + 1;
		else
			++it1, ++it2;
	return *s.rbegin() + 1;
}
inline void dfs_calc(ll cur)
{
	s[cur].insert(w[cur]);
	for(const ll& nxt : child[cur])
	{
		dfs_calc(nxt);
		set_merge(s[cur], s[nxt]);
	}
}
inline void dfs_find(ll cur, ll lim)
{
	if(cur > n)
	{
		ll ret = 0;
		for(int i = 1; i <= n; ++i)
			s[i].clear();
		dfs_calc(1);
		for(int i = 1; i <= n; ++i)
			ret += mex(s[i]);
		if(ret >= ans)
			ans = ret;
		return;
	}
	for(int i = 0; i <= lim; ++i)
	{
		w[cur] = i;
		dfs_find(cur + 1, lim);
	}
}
namespace sol2
{
	bool vis[N];
	ll csize[N], tag[N];
	struct nd{ ll size, nxtid; };
	inline void init()
	{
		for(int i = 1; i <= n; ++i)
			csize[i] = 0, tag[i] = 0;
		time_stamp = 0;
	}
	inline void pre_dfs(ll cur)
	{
		csize[cur] = 1;
		for(const ll& nxt : child[cur])
		{
			pre_dfs(nxt);
			csize[cur] += csize[nxt];
		}
	}
	inline void tag_dfs(ll cur)
	{
		vector<nd> ord;
		for(const ll& nxt : child[cur])
			ord.push_back({csize[nxt], nxt});
		sort(ord.begin(), ord.end(), [](nd& l, nd& r){ return l.size > r.size; });
		for(const nd& nxt : ord)
			tag_dfs(nxt.nxtid);
		tag[cur] = time_stamp++;
	}
	inline void bind_dfs(ll cur)
	{
		s[cur].insert(tag[cur]);
		for(const ll& nxt : child[cur])
		{
			bind_dfs(nxt);
			set_merge(s[cur], s[nxt]);
		}
	}
}
signed main()
{
	ifstream cin("tree.in", ios::binary);
	ofstream cout("tree.out", ios::binary);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
		{
			child[i].clear();
			s[i].clear();
		}
		for(int i = 2; i <= n; ++i)
			cin >> fa[i], child[fa[i]].push_back(i);
		ans = 0;
		if(n <= 8)
		{
			ll lim = n / 2 + (n % 2);
			dfs_find(1, lim);
		}
		if(n > 8)
		{
			sol2::init();
			sol2::pre_dfs(1);
			sol2::tag_dfs(1);
			sol2::bind_dfs(1);
		}
		for(int i = 1; i <= n; ++i)
			ans += mex(s[i]);
		cout << ans << "\n";
	}
}



