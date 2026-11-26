#include<bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define bint __int128
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
int T;
bool Pos1;
const int N=8e3+5,inf=1e9+7;
int n,m;
int f[N][N];
int g[N],sz[N];
vector<int> to[N];
void dfs(int u){
	sz[u]=1;
	f[u][0]=0;
	for(int i=1;i<=n;i++)f[u][i]=-inf;
	for(int v:to[u]){
		dfs(v);
		for(int i=1;i<=sz[u];i++)g[i]=f[u][i];
		for(int i=1;i<=sz[u]+sz[v];i++)f[u][i]=-inf;
		for(int j=1;j<=sz[v];j++){
			for(int k=0;k<=sz[u];k++){
				chkmax(f[u][max(j,k)],g[k]+f[v][j]);
			}
		}
		for(int k=0;k<=sz[u];k++)chkmax(f[u][k+sz[v]],g[k]);
		sz[u]+=sz[v];
	}
	for(int i=0;i<=sz[u];i++)g[i]=f[u][i];
	for(int i=1;i<=sz[u];i++)f[u][i]=g[i-1]+i;	
}
void Sub1(){
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)chkmax(ans,f[1][i]);
	cout<<ans<<endl;
}
const int M=365;
int dp[M][M][M];
int h[M][M];
void dfs0(int u){
	sz[u]=1;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[u][i][j]=-inf;
	dp[u][0][0]=0;
	for(int v:to[u]){
		dfs0(v);
		for(int i=0;i<=sz[u];i++)for(int j=0;j<=sz[u];j++){
			h[i][j]=dp[u][i][j];
			dp[u][i][j]=-inf;
		}
		for(int i=0;i<=sz[v];i++)for(int sv=0;i+sv<=sz[v];sv++){
			for(int j=0;j<=sz[u];j++)for(int su=0;j+su<=sz[u];su++){
				int nl=max(i,j);
				int nv=sv+su;
				chkmax(dp[u][nl][nv],dp[v][i][sv]+h[j][su]);
			}
		}
		sz[u]+=sz[v];
	}
	for(int i=0;i<=sz[u];i++)for(int j=0;j<=sz[u];j++)h[i][j]=dp[u][i][j];
	for(int tot=0;tot<=sz[u];tot++){
		int suf=0;
		for(int k=tot;~k;k--){
			chkmax(h[tot-k][k],suf);
			chkmax(suf,h[tot-k][k]);
		}
	}
	for(int i=0;i<=sz[u];i++)for(int j=0;j<=sz[u];j++){
		if(i)chkmax(dp[u][i][j],h[i-1][j]);
		if(j)chkmax(dp[u][i][j],h[i][j-1]);
		dp[u][i][j]+=i;
	}
	
}
void Sub2(){
	dfs0(1);
	int ans=0;
	for(int i=1;i<=n;i++)chkmax(ans,dp[1][i][0]);
	cout<<ans<<endl;
}
void solve(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)to[i].clear();
	for(int i=2;i<=n;i++){
		int p; cin>>p;
		to[p].pb(i);
	}
	if((m==2)||(n>360))Sub1();
	else Sub2();
	
}
bool Pos2;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
code:
!noip@Nov29,2025:dream
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
