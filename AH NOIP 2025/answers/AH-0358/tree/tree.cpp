#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,mxn[8005],num[8005],nm2[8005];
long long dp[8005];
vector<int>d[8005];
void dfs(int u){
	num[u]=1;
	for(int v : d[u]){
		nm2[v]=nm2[u]+1;
		dfs(v);
		num[u]+=num[v];	
	}
	for(int k=0;k<(1<<(d[u].size()));k++){
		int nx=0,pmx=0,k1=k;
		long long ans1=0;
		for(int v : d[u]){
			if(k1&1){
				ans1+=dp[v];
				pmx=max(pmx,mxn[v]);
			}else{
				nx+=num[v];
			}
			k1>>=1;
		}
		ans1+=nx+pmx+1;
		if(ans1+(nx+pmx+1)*nm2[u]>dp[u]+mxn[u]*nm2[u])dp[u]=ans1,mxn[u]=nx+pmx+1;
	}
}
void solve(){
	memset(dp,0,sizeof(dp));
	memset(mxn,0,sizeof(mxn));
	memset(num,0,sizeof(num));
	memset(nm2,0,sizeof(nm2));
	cin>>n>>m;
	for(int i=1;i<=n;i++)d[i].clear();
	for(int i=2;i<=n;i++){
		int xi;
		cin>>xi;
		d[xi].push_back(i);
	}
	dfs(1);
	cout<<dp[1]<<endl;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
