#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=4005;
int n,m,sz[N],tp[N][N],pre1[N],pre2[N];vector<int>e[N],f[N][405];
inline void ckmx(int &u,int v) {if(v>u) u=v;}
inline void dfs(int x) {
	sz[x]=1;int szz=sz[x];
	for(int y:e[x]) dfs(y),szz+=sz[y];
	for(int i=0;i<=min(m,szz);++i) vector<int>().swap(f[x][i]),f[x][i].resize(szz+5);f[x][1][0]=0;
	for(int y:e[x]) {
		fr(i,0,sz[x]+sz[y]) for(int j=0;j<=min(2*m,sz[x]+sz[y]-i);++j) tp[i][j]=0;
		for(int j=0;j<=min(m,sz[x]);++j) for(int j2=0;j2<=min(m,sz[y]);++j2) {
			pre1[0]=f[x][j][0],pre2[0]=f[y][j2][0];
			for(int i=1;i<=sz[x]-j;++i) pre1[i]=max(pre1[i-1],f[x][j][i]);
			for(int i=1;i<=sz[y]-j2;++i) pre2[i]=max(pre2[i-1],f[y][j2][i]);
			for(int i=1;i<=sz[x]-j;++i) ckmx(tp[i][j+j2],f[x][j][i]+pre2[min(sz[y]-j2,i)]);
			for(int i=1;i<=sz[y]-j2;++i) ckmx(tp[i][j+j2],f[y][j2][i]+pre1[min(sz[x]-j,i)]);
		}
		sz[x]+=sz[y];
		for(int i=0;i<sz[x];++i) for(int j=1;j<=min(m*2,sz[x]-i);++j) ckmx(tp[i+1][j-1],tp[i][j]);
		fr(i,0,sz[x]) for(int j=0;j<=min(m,sz[x]-i);++j) f[x][j][i]=tp[i][j];
	}
	for(int i=0;i<=sz[x];++i) for(int j=0;j<=min(m,sz[x]-i);++j) f[x][j][i]+=i;
	return ;
}
inline void work() {
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&m);m*=2;
	fr(i,1,n) e[i].clear();
	for(int i=2;i<=n;++i) {int x;scanf("%d",&x);e[x].push_back(i);}
	dfs(1);
	int ans=0;fr(i,1,n) ckmx(ans,f[1][0][i]);
	printf("%d\n",ans);
	return ;
}
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) work();
	return 0;
}