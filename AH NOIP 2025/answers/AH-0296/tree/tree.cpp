#include<bits/stdc++.h>
using namespace std;
int T,n,m,p[8008],fa[8008],zs[8008],ans,sd[8008],bj[8008];
vector<int> e[8008];
void dfs1(int u){
	zs[u]++;
	if(u!=1 && e[u].size()==1){
		if(bj[fa[u]]==0){bj[fa[u]]=1;ans+=zs[u];}
		return;
	}
	for(int i=0;i<e[u].size();i++){
		if(e[u][i]==fa[u]) continue;
		dfs1(e[u][i]);
		zs[u]+=zs[e[u][i]];
	}
	ans+=zs[u];
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(p,0,sizeof(p));
		memset(fa,0,sizeof(fa));
		memset(zs,0,sizeof(zs));
		memset(sd,0,sizeof(sd));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++){
			scanf("%d",&fa[i]);
			e[i].push_back(fa[i]);
			e[fa[i]].push_back(i);
		}
		dfs1(1);
		printf("%d\n",ans-1);
	}
}
