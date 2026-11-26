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

const int N = 81;

const int M = 810;

int T;

int n,m;

int val[N];

int dep[N];

int sz[N];

vector<int> G[N];

// void dfs(int u,int fa){
// 	sz[u] = 1;
// 	dep[u] = dep[fa] + 1;
// 	for(int v : G[u]){
// 		if(v == fa) continue;
// 		dfs(v,u);
// 		sz[u] += sz[v];
// 	}
// 	a[dep[u]] = max(a[dep[u]],sz[u]);
// }

map<int,int> st[N];

int ress = 0,anss;

//int flag = 0;

void dfs1(int u,int fa){
	st[u][val[u]] = 1;
	for(int v : G[u]){
		if(v == fa) continue;
		dfs1(v,u);
		for(auto x : st[v]){
			st[u][x.fi] = 1; 
		}
	}
	// if(flag <= 2){
	// 	cerr << u << ':';
	// 	for(auto x : st[u]){
	// 		cerr << x.fi << ' ';
	// 	}
	// 	cerr << endl;
	// }

	//cerr << u << ' ' << SZ(st[u]) << endl;
	for(int i = 0;;i++){
		if(st[u].count(i) == 0) {
			//cerr << u << ' ' << i << endl;
			ress += i;
			break;
		}
	}
}

void ffo(int u){
	if(u == n + 1){
		rep(i,0,10) st[i].clear();
		ress = 0;
		dfs1(1,0);
		//cerr << ress << endl;
		anss = max(anss,ress);
		//flag++;
		return ;
	}
	rep(i,0,n){
		val[u] = i;
		ffo(u + 1);
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	//cerr << n << endl;
	rep(i,0,n + 1) G[i].clear();
	rep(u,2,n){
		int v;
		scanf("%d",&v);
		G[u].pb(v);
		G[v].pb(u);
	}

	ffo(1);
	//ll ans = 0;
	printf("%d\n",anss);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}