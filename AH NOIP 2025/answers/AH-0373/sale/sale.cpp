#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
int n,m,ans,a[100010],b[100010],c[100010],dp[100010];
bool cmp(int x,int y){
	return a[x] * b[y] == a[y] * b[x] ? a[x] > a[y] : a[x] * b[y] > a[y] * b[x];
}
bool check(){
	int i,j,s = m,sum = 0;
	memset(dp,0,sizeof(dp));
	rep(i,1,n,1) r(j,m,b[i],1) dp[j] = max(dp[j],dp[j - b[i]] + a[i]);
	rep(i,1,n,1) c[i] = i;
	sort(c + 1,c + n + 1,cmp);
	rep(i,1,n,1) if(s >= b[c[i]]) s -= b[c[i]],sum += a[c[i]];
	return sum == dp[m];
}
void dfs(int x){
	if(x > n){
		ans += check();
		return ;
	}
	b[x] = 1;
	dfs(x + 1);
	b[x] = 2;
	dfs(x + 1);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int i,t;
	cin>>t>>t;
	while(t--){
		cin>>n>>m;
		rep(i,1,n,1) cin>>a[i];
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
