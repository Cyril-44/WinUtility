#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define F(x) ((x) % P)
#define FE(x) ((x) %= P)
using namespace std;
using ll = long long;
using db = double;
using PII = pair<int,int>;
using PLL = pair<ll,ll>;
constexpr int infI = 1 << 30;
constexpr ll infL = 1ll << 60;

map<int,int> mp;

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	mp[0] = 1,mp[2] = 3,mp[5] = 4;
	for(auto x : mp){
		cerr << x.fi << endl;
		cerr << mp.count(x.fi + 1) << endl;
	}
	return 0;
}