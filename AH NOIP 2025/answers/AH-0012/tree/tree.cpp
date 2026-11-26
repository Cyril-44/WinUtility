#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pii pair<int,int>
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=4e3+5;
const int inf=1e9;
vector<int>g[N];
int T,n,m,siz[N],de[N],md[N],f[365][365],dp[365][365][365];
inline void dfs1(int u,int fa){
	de[u]=de[fa]+1,md[u]=siz[u]=1;
	for(int v:g[u])dfs1(v,u),md[u]=max(md[u],md[v]+1),siz[u]+=siz[v];
}
inline void dfs2(int u,int fa){
	if(!g[u].size()){
		dp[u][1][0]=1,dp[u][0][1]=0;
		return;
	}
	dp[u][0][0]=0;
	int m1=0,m2=0,mx=0,son=-1;
	for(int v:g[u])if(siz[v]>mx)mx=siz[v],son=v;
	for(int v:g[u])if(v!=son){
		dfs2(v,u);
		for(int i=0;i<=max(m1,siz[v]);i++)for(int j=0;j<=m2+siz[v];j++){
			f[i][j]=dp[u][i][j],dp[u][i][j]=-inf;
		}
		for(int i=0;i<=siz[v];i++)for(int j=0;j<=siz[v];j++){
			for(int ii=0;ii<=m1;ii++)for(int jj=0;jj<=m2;jj++){
				dp[u][max(i,ii)][j+jj]=max(dp[u][max(i,ii)][j+jj],dp[v][i][j]+f[ii][jj]);
			}
		}
		m1=max(m1,siz[v]),m2+=siz[v];
	}
	{
		int v=son;
		dfs2(v,u);
		for(int i=0;i<=max(m1,siz[v]);i++)for(int j=0;j<=m2+siz[v];j++){
			f[i][j]=dp[u][i][j],dp[u][i][j]=-inf;
		}
		for(int i=0;i<=siz[v];i++)for(int j=0;j<=siz[v];j++){
			for(int ii=0;ii<=m1;ii++)for(int jj=0;jj<=m2;jj++){
				dp[u][max(i,ii)][j+jj]=max(dp[u][max(i,ii)][j+jj],dp[v][i][j]+f[ii][jj]);
			}
		}
		m1=max(m1,siz[v]),m2+=siz[v];
	}
	for(int i=0;i<=siz[u];i++)for(int j=0;j<=siz[u];j++)f[i][j]=dp[u][i][j],dp[u][i][j]=-inf;
	for(int i=0;i<=m1;i++)for(int j=0;j<=m2;j++){
		dp[u][i+1][j]=max(dp[u][i+1][j],f[i][j]+i+1);
		dp[u][i+j+1][0]=max(dp[u][i+j+1][0],f[i][j]+i+j+1);
		dp[u][i][j+1]=max(dp[u][i][j+1],f[i][j]+i);
	}
}
namespace sub2{
	void solve(){

	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	for(cin>>T;T;T--){
		in(n),in(m);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=2,u;i<=n;i++)in(u),g[u].push_back(i);
		dfs1(1,0);
		if(n>360){sub2::solve();continue;}
		memset(dp,-0x3f,sizeof dp);dfs2(1,0);
		int ans=0;
		for(int i=0;i<=siz[1];i++)for(int j=0;j<=siz[1];j++)ans=max(ans,dp[1][i][j]);
		cout<<ans<<endl;
	}
	return 0;
}