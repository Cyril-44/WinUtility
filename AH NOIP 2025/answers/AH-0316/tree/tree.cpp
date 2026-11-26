#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())
#define pb push_back
#define fi first
#define se second


using namespace std;

const int N=100;
int n,m,p[N],l[N],r[N],tot,dfn[N],a[N],ans;
vector<int>g[N];bool st[N];
int get(){
	int s=0;
	rep(i,1,n){
		rep(j,0,n+1)st[j]=0;
		int mex=0;
		rep(j,l[i],r[i]){
			st[a[j]]=1;
			while(st[mex])++mex;
		}
		s+=mex;
	}
	return s;
}
void dfss(int x){
	l[x]=++tot;dfn[tot]=x;
	rep(i,0,SZ(g[x])-1){
		dfss(g[x][i]);
	}
	r[x]=tot;
}
void dfs(int x){
	if(x>n){
		ans=max(ans,get());
		return;
	}
	rep(j,0,n){
		a[x]=j;
		dfs(x+1);
	}
}
void solve(){
	cin>>n>>m;tot=ans=0;
	rep(i,1,n)g[i].clear();
	rep(i,2,n)cin>>p[i],g[p[i]].pb(i);
	dfss(1);
	dfs(1);
	cout<<ans<<'\n';
}


int main(){

	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	int T=1;
	cin>>T;
	while(T--)solve();

	return 0;
}
