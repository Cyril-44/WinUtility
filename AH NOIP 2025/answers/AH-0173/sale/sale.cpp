#include<iostream>
#include<algorithm>
using namespace std;
int a[5050];
int c[5050];
int n,m;
struct tang{
	double qian;
	int yuan;
	int xian;
}h[5050];
int dp[5050][100];
bool ch(tang x,tang y){
	if(x.qian==y.qian){
		return x.yuan>y.yuan;
	}
	return x.qian>y.qian;
}
int ans=0;
void dfs(int q){
	if(q==n+1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			h[i].qian=a[i]*1.0/c[i];
			h[i].yuan=a[i];
			h[i].xian=c[i];
		}
		sort(h+1,h+1+n,ch);
		int d=m;
		int ans1=0;
		for(int i=1;i<=n;i++){
			if(d>=h[i].xian){
				d-=h[i].xian;
				ans1+=h[i].yuan;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j-c[i]>=0){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+a[i]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		if(ans1==dp[n][m]){
			ans++;
		}
		return;
	}
	c[q]=1;
	dfs(q+1);
	c[q]=2;
	dfs(q+1);
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c1,t;
	cin>>c1>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			h[i].yuan=0;
			h[i].xian=0;
			h[i].qian=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
