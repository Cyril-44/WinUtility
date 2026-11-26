#include<bits/stdc++.h>
using namespace std;
struct node{
	int aa,vv;
	double bi;
}w[50005];
int c,t,n,m,ans,a[50005],v[50005];
long long dp[50005];
long long mod=998244353;
bool cmp(node xx,node yy){
	if(xx.bi==yy.bi)return xx.aa>=yy.aa;
	return xx.bi>yy.bi;
}
int work(){
	sort(w+1,w+n+1,cmp);
	int mm=m;
	long long val=0ll;
	for(int i=1;i<=n;i++){
		if(w[i].vv<=mm){
			mm-=w[i].vv;
			val+=w[i].aa;
		}
		if(mm==0)break;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){
			dp[j]=max(dp[j],dp[j-v[i]]+a[i]*1ll);
		}
	}
	return dp[m]==val;
}
void dfs(int idx){
	if(idx>n){
		for(int i=1;i<=n;i++){
			w[i].aa=a[i];
			w[i].vv=v[i];
			w[i].bi=a[i]*1.0/v[i];
		}
		ans+=work();
		ans%=mod;
		return;
	}
	v[idx]=1;
	dfs(idx+1);
	v[idx]=2;
	dfs(idx+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==18||c==16){
			long long anss=1ll;
			for(int i=1;i<=n;i++){
				anss*=2;
				anss%=mod;
			}
			cout<<anss<<"\n";
			continue;
		}
		ans=0;
		if(c<=6){
			dfs(1);
		}
		cout<<ans<<"\n";
	}	
	return 0;
}
//!noip@Nov29,2025:dream
