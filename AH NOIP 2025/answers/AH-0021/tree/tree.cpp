#include<bits/stdc++.h>
using namespace std;
const int N=8e3+5;
vector<int>eg[N];
int n,m,cost,a[N],b[N],ans=0,al=0,no=0,T,sz[N];
// int dp[N][N][N],d[N][N],sz[N];
// int f[N][N][N],g[N][N][N],w[N];
void dfs(int u){
	sz[u]=1;
	int mx=0;
	for(auto v:eg[u]){
		dfs(v);sz[v]+=sz[u];
		mx=max(mx,sz[v]);
	}
	if(sz[u]!=1){
		if(u!=1)ans+=sz[u]+1;
		else ans+=mx+1;
	}
}
// void dfs(int u){
// 	sz[u]=1;
// 	vector<int>son;
// 	for(auto v:eg[u]){
// 		son.push_back(v);
// 		dfs(v);
// 		sz[u]+=sz[v];
// 	}
// 	int L=(int)son.size(),al=0;
// 	for(int i=0;i<L-1;i++){//长度
// 		int v=son[i];
// 		for(int j=0;j<=sz[son];j++){
// 			if(d[v][j]==0)continue;
// 			for(int k=0;k<=al;k++){
// 				chkmx(f[u][i+1][j+k],f[u][i][k]+d[v][j]);
// 			}
// 		}
// 		al+=sz[v];
// 	}
// 	al=0;
// 	for(int i=0;i<L-1;i++){
// 		int v=son[L-1-i];
// 		for(int j=0;j<=sz[son];j++){
// 			if(d[v][j]==0)continue;
// 			for(int k=0;k<=al;k++){
// 				chkmx(g[u][i+1][j+k],g[u][i][k]+d[v][j]);
// 			}
// 		}
// 	}
// 	for(int i=0;i<L;i++){
// 		int v=son[i],lt=i,rt=L-i-1;
// 		for(int j=0;j<=sz[v];j++){
// 			for(int k=0;k<=sz[v];k++){
// 				if(dp[v][j][k]==0)continue;

// 			}

// 		}
// 	}
// }
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int F;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)eg[i].clear();
		for(int i=2;i<=m;i++){
			scanf("%d",&F);
			eg[F].push_back(i);
		}
		if(m==1){
			printf("%d\n",n+1);
			continue;
		}
		if(m==2){
			ans=0;
			dfs(1);
			printf("%d\n",ans);
		}
	}	
	return 0;
}