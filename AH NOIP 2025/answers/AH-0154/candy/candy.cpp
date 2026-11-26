
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int x[100001],y[100001];
ll n,m;
ll dp[100001][2];

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		//printf("%d",x[i]);
	}
	
	for(int i=0;i<=m;i++){
		dp[i][0]=-1;dp[i][1]=-1;
	}
	
		
	dp[0][1]=0;
	// 0 ji 1 ou
	for(int i=1;i<=n;i++){
		//printf("%d",x[i]);
		for(int j=0;j<=m;j++){
			if(j-x[i]>=0 && dp[j-x[i]][1]!=-1)
				dp[j][0]=max(dp[j][0],dp[j-x[i]][1]+1);
			if(j-y[i]>=0 && dp[j-y[i]][0]!=-1)
				dp[j][1]=max(dp[j][1],dp[j-y[i]][0]+1);
		}
		
		for(int j=0;j<=m;j++){
			if(dp[j][0]!=-1){dp[j][1]=max(dp[j][1],dp[j][0]);
			dp[j][0]=-1;}
		}
		//for(int k=0;k<=m;k++){
		//printf("%lld %lld \n", dp[k][0],dp[k][1]);
		//}printf("\n");
	}
	
	ll ans=0;
	for(int i=0;i<=m;i++){
		ans=max(ans, max(dp[i][0],dp[i][1]));
	}
	cout<<ans;
	return 0;
}
