#include<bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=8000+10;

int T,n,m,tot,dfn[MAXN],sze[MAXN],dp[MAXN][805],pre[MAXN][805],dep[MAXN],rev[MAXN];
vector<int> G[MAXN];

namespace BIT {
	int tr[805][MAXN];
	void update(int o,int pos,int v) {
		while(pos<=n) tr[o][pos]+=v,pos+=pos&-pos;
		return ;
	}
	int query(int o,int pos) {
		int ans=0;
		while(pos) ans+=tr[o][pos],pos-=pos&-pos;
		return ans;
	}
	void init(void) {memset(tr,0,sizeof(tr)),tot=0;}
	void add(int o,int u,int v) {
		update(o,dfn[u],v);
		update(o,dfn[u]+sze[u],-v);
		return ;
	}
};

void dfs0(int u,int f) {
	sze[u]=1,dfn[u]=++tot,dep[u]=dep[f]+1,rev[tot]=u;
	for(auto v:G[u]) dfs0(v,u),sze[u]+=sze[v];
	return ;
}
void dfs(int u,int f) {
	for(auto v:G[u]) dfs(v,u);
	ffor(s,0,800) {
		int sum=0;
		for(auto v:G[u]) sum+=dp[v][s];
		for(auto v:G[u]) BIT::add(s,v,sum-dp[v][s]);
	}
	ffor(s,0,800) dp[u][s]=sze[u]*s;
	ffor(s,0,800) {
		int mx=-INT_MAX,sum=s;
		for(auto v:G[u]) sum+=dp[v][s],mx=max(mx,pre[v][s+1]-dp[v][s]);
		if(G[u].empty()) pre[u][s]=s;
		else pre[u][s]=sum+mx;
	}
	dp[u][0]=pre[u][1],dp[u][1]=max(dp[u][1],pre[u][1]);
	ffor(i,dfn[u]+1,dfn[u]+sze[u]-1) {
		int v=rev[i],dis=dep[v]-dep[u]+1;
		dp[u][dis]=max(dp[u][dis],pre[v][dis]+BIT::query(dis,i)+dis*(dis-1));
	}
	return ;
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		memset(dp,0,sizeof(dp)),memset(pre,0,sizeof(pre));
		BIT::init();
		cin>>n>>m;
		ffor(i,1,n) G[i].clear();
		ffor(i,2,n) {
			int fa;
			cin>>fa,G[fa].push_back(i);
		}
		dfs0(1,0);
		dfs(1,0);
		cout<<dp[1][0]<<'\n';
	}
	return 0;
}