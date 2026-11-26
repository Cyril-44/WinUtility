#include "bits/stdc++.h"
using namespace std;
const int MAXS=1<<19,N=20,inf=1e6+7;
int getmex(int s){
	int k=0;
	while(s&(1<<k))k++;
	return k;
}
vector<int>e[N];
int n,m,LIM=0,Ans=0;
void init(){
	scanf("%d%d",&n,&m),Ans=0;
	for(int i=1;i<n;i++)e[i].clear();
	for(int u,v=2;v<=n;v++){
		scanf("%d",&u);
		e[u].emplace_back(v);
	}
	if(n<20)LIM=n;
}
void sufsm(int *f){
	int S=1<<LIM;
	for(int k=1;k<S;k<<=1)
	for(int s=1;s<S;s++)
		if(s&k)f[s^k]=max(f[s^k],f[s]);
}
int g[MAXS],tf[MAXS],f[N][MAXS];
void dfs(int u,int Fa){
	for(auto v:e[u])dfs(v,u);
	for(int s=0;s<(1<<LIM);s++)f[u][s]=-inf;
	for(int c=0;c<LIM;c++)f[u][(1<<c)]=0;
	for(auto v:e[u]){
		for(int s=0;s<(1<<LIM);s++)g[s]=f[v][s],tf[s]=f[u][s],f[u][s]=-inf;
		sufsm(g),sufsm(tf);
		for(int s=0;s<(1<<LIM);s++)
		for(int s1=s;s1>0;s1=(s1-1)&s){
			f[u][s]=max(f[u][s],tf[s1]+g[s^s1]);
		}
	}
	for(int s=0;s<(1<<LIM);s++)
		f[u][s]+=getmex(s);
}
void work(){
	dfs(1,0);
	Ans=0;
	for(int s=0;s<(1<<LIM);s++)Ans=max(Ans,f[1][s]);
	printf("%d\n",Ans);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	return 0;
}