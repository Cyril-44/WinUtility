#include<bits/stdc++.h>
using namespace std;
const int Maxn=8005,INF=1e9;
int f[55][Maxn],g[55][Maxn][55],h[55][Maxn],hh[55][Maxn],tmpf[Maxn],tmpg[Maxn][55],tmph[Maxn],tmphh[Maxn],w[Maxn];
int pre[Maxn],head[Maxn],val[Maxn],len;
int sz[Maxn],n,m,ans,mxn[Maxn];
void ins(int u,int v){pre[++len]=head[u];head[u]=len;val[len]=v;}
void chkmx(int &a,int b){if (a<b) a=b;}
void dfs1(int u,int d){
	for(int j=0;j<=n;++j) for(int k=0;k<=m;++k) g[d][j][k]=hh[d][j]=-INF;
	for(int i=0;i<=n;++i) f[d][i]=h[d][i]=-INF;
	sz[u]=1;
	for(int j=0;j<=m;++j) g[d][1][j]=0;
	f[d][1]=h[d][1]=g[d][1][0]=hh[d][1]=0;
	for(int i=head[u];i;i=pre[i]){
		int v=val[i];
		dfs1(val[i],d+1);
		for(int j=0;j<=sz[v];++j) w[j]=-INF;
		for(int j=0;j<=sz[v]+sz[u];++j) for(int k=0;k<=m;++k){
			tmpg[j][k]=tmphh[j]=-INF;
		}
		for(int j=0;j<=sz[u]+sz[v];++j) tmpf[j]=tmph[j]=-INF;
		for(int j=0;j<=sz[u];++j) for(int k=0;k<=sz[v];++k) for(int c=0;c<=m;++c){
			chkmx(tmpg[j+k][c],g[d][j][c]+g[d+1][k][0]);
			chkmx(tmpg[j][c],g[d][j][c]+f[d+1][k]);
			chkmx(tmpg[j+k][c],hh[d][j]+g[d+1][k][c]);
			chkmx(tmphh[j+k],hh[d][j]+g[d+1][k][0]);
			chkmx(tmphh[j],hh[d][j]+f[d+1][k]);
		}
		for(int j=0;j<=sz[u];++j) for(int k=0;k<=sz[v];++k){
			chkmx(tmpf[j+k],f[d][j]+g[d+1][k][0]);
			chkmx(tmpf[j],f[d][j]+f[d+1][k]);
			chkmx(tmph[j+k],f[d][j]+f[d+1][k]);
			chkmx(tmph[j+k],h[d][j]+g[d+1][k][0]);
			chkmx(tmph[j],h[d][j]+f[d+1][k]);
		}
		sz[u]+=sz[v];
		for(int j=0;j<=sz[u];++j) for(int k=0;k<=m;++k) g[d][j][k]=tmpg[j][k],hh[d][j]=tmphh[j];
		for(int j=0;j<=sz[u];++j) f[d][j]=tmpf[j],h[d][j]=tmph[j];
	}
	for(int j=0;j<=sz[u];++j) f[d][j]=h[d][j]+j;
	mxn[u]=0;
	for(int j=0;j<=sz[u];++j) mxn[u]=max(mxn[u],f[d][j]);
	for(int k=0;k<=sz[u];++k){
		for(int j=0;j<m;++j) g[d][k][j]=g[d][k][j+1];
		g[d][k][m]=-INF;
	}
	for(int k=0;k<=sz[u];++k) for(int j=0;j<=m;++j) g[d][0][j]=max(g[d][0][j],f[d][k]+j*k);
}
void work(){
	scanf("%d%d",&n,&m);len=0;
	for(int i=1;i<=n;++i) head[i]=0;
	for(int i=2,fa;i<=n;++i){scanf("%d",&fa);ins(fa,i);}
	dfs1(1,1);printf("%d\n",mxn[1]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--) work();
	return 0;
}
