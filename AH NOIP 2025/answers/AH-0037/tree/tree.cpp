#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define req(i,a,b) for(int i=a;i>=b;--i)
int Test;
const int N=8005;
int n,m,fa[N],dep[N],siz[N],val[N],flag[N];
ll res=0;
vector<int> g[N];
int dfs1(int u){
	siz[u]=1;
	if(g[u].size()==0){val[u]=0;return dep[u];}
	int mxdep=dep[u];
	for(int v:g[u]){
		dep[v]=dep[u]+1;
		mxdep=max(mxdep,dfs1(v));
		siz[u]+=siz[v];
	}
	if(dep[u]==mxdep-1){
		int nowc=0;
		for(int v:g[u]){
			val[v]=nowc++;
		} 
		val[u]=nowc;res+=val[u]+1;
	} else {
		for(int v:g[u])val[u]=max(val[v],val[u]);
		++val[u];res+=val[u]+1;
	} return mxdep;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>Test;while(Test--){
		cin>>n>>m;res=0;
		rep(i,1,n)g[i].clear();
		rep(i,2,n){
			cin>>fa[i];
			g[fa[i]].push_back(i);
		} 
			if(m==1){cout<<n+1<<'\n';continue;}
			dep[1]=0;
			dfs1(1);
			rep(i,1,n)if(g[i].size()==0)flag[fa[i]]=1;
			rep(i,1,n)res+=flag[i],flag[i]=0;
			cout<<res<<'\n';
	}
	return 0;
}
