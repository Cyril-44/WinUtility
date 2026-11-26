#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int ans;
int p[5005];
vector<int> g[5005];
int f[5005];
int w[10];
int dfs2(int u);
bool vis[10][10];
void dfs1(int u){
	if(u==n+1) {memset(vis,0,sizeof(vis));ans=max(ans,dfs2(1));return;}
	for(int i=0;i<n;i++){
		w[u]=i;
		dfs1(u+1);
	}
}
int dfs2(int u){
	int s=0;
	vis[u][w[u]]=1;
	for(int v:g[u]){
		s+=dfs2(v);
		for(int i=0;i<n;i++) vis[u][i]|=vis[v][i];
	}
	for(int i=0;i<=n;i++){
		if(vis[u][i]==0){s+=i;break;}
	}
	return s;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=2;i<=n;i++){
			cin>>p[i];
			g[p[i]].push_back(i);
		}
		dfs1(1);
		cout<<ans<<'\n';
	}
	return 0;
}
