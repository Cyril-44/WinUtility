#include <bits/stdc++.h>
using namespace std;

int dp[125][125][125]; // ith 0~j-1 k left 
int mxdp[125][125][125];
vector<int>a[8005];
int n,m;
int siz[125];
void dfs(int w,int fa){
	dp[w][0][0]=0;
	int rdp[125][125][2];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			rdp[i][j][0]=-1,rdp[i][j][1]=-1;
		}
	}
	rdp[0][0][1]=rdp[0][0][0]=0;
	for(int i=0;i<a[w].size();i++){
		if (a[w][i]==fa) continue;
		dfs(a[w][i],w);
		for(int j=n;j>=0;j--){
			for(int z=n;z>=0;z--){
				int pp=max(rdp[j][z][0],rdp[j][z][1]);
				if (rdp[j][z][1]!=-1) rdp[j][z][1]=max(rdp[j][z][1],rdp[j][z][1]+mxdp[a[w][i]][j][0]);
				if (pp!=-1&&mxdp[a[w][i]][j][0]!=-1)rdp[j][z][0]=max(pp+mxdp[a[w][i]][j][0],rdp[j][z][0]);
				if (pp!=-1&&dp[a[w][i]][j][0]!=-1)rdp[j][z][1]=max(pp+dp[a[w][i]][j][0],rdp[j][z][1]);
				rdp[j][z][0]=max(rdp[j][z][0],mxdp[a[w][i]][j][z]);
				rdp[j][z][1]=max(rdp[j][z][1],dp[a[w][i]][j][z]);
				for(int z1=z;z1>=1;z1--){
					//0
					if (max(rdp[j][z-z1][0],rdp[j][z-z1][1])!=-1&&mxdp[a[w][i]][j][z1]!=-1) rdp[j][z][0]=max(rdp[j][z][0],max(rdp[j][z-z1][0],rdp[j][z-z1][1])+mxdp[a[w][i]][j][z1]);
					if (max(rdp[j][z-z1][0],rdp[j][z-z1][1])!=-1&&dp[a[w][i]][j][z1]!=-1) rdp[j][z][1]=max(max(rdp[j][z-z1][0],rdp[j][z-z1][1])+dp[a[w][i]][j][z1],rdp[j][z][1]);
					if (rdp[j][z-z1][1]!=-1&&mxdp[a[w][i]][j][z1]!=-1) rdp[j][z][1]=max(rdp[j][z][1],rdp[j][z-z1][1]+mxdp[a[w][i]][j][z1]);
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[w][i][j]=rdp[i][j][1];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int z=1;z<=i;z++){
				if (j+z<=n) dp[w][i][j]=max(dp[w][i-z][j+z],dp[w][i][j]);
			}
		}
	}
	for(int i=n;i>=0;i--){
		for(int j=n;j>=0;j--){
			if (j!=0)dp[w][i][j]=max(dp[w][i][j],dp[w][i][j-1]);
			if (i!=0)dp[w][i][j]=max(dp[w][i][j],dp[w][i-1][j]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int z=1;z<=i;z++){
				if (j+z<=n) dp[w][i][j]=max(dp[w][i-z][j+z],dp[w][i][j]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if (dp[w][i][j]!=-1) dp[w][i][j]+=i;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			mxdp[w][i][j]=dp[w][i][j];
			if (i!=0) mxdp[w][i][j]=max(mxdp[w][i][j],mxdp[w][i-1][j]);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=2;i<=n;i++){
			int u,v=i;
			cin>>u;
			a[u].push_back(v);
			a[v].push_back(u);
		}
//		if (n<=120){
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int z=0;z<=n;z++){
						mxdp[i][j][z]=dp[i][j][z]=-1;
					}
				}
			}			
			dfs(1,0);
			int ans=0;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					ans=max(ans,dp[1][i][j]);
				}
			}
			cout<<ans<<endl;
			continue;
	//	}
	}
	return 0;
}
