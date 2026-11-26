#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],dp[1005][10005];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int m1=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=m;i++){
		dp[1][i]=dp[1][i-1];
		if(cnt%2==0&&x[1]<=i-m1){
			m1+=x[1];
			dp[1][i]++;
			cnt++;
		}
		if(cnt%2==1&&y[1]<=i-m1){
			m1+=y[1];
			dp[1][i]++;
			cnt++;
		}
	}
	//for(int i=1;i<=m;i++){
	//	cout<<dp[1][i]<<" ";
	//}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			int c1=0,c2=0;
			if(j-y[i]>=0||j-x[i]>=0){
				if(j-x[i]>=0)
				if(dp[i-1][j-x[i]]%2==0){
					c1=max(max(dp[i-1][j],dp[i][j-x[i]]+1),dp[i][j-1]);
				}
				if(j-y[i]>=0)
				if(dp[i-1][j-y[i]]%2==1){
					c2=max(max(dp[i-1][j],dp[i][j-y[i]]+1),dp[i][j-1]);
				}
			}
			else c1=c2=dp[i-1][j];
			dp[i][j]=max(max(c1,c2),dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
