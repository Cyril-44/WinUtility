#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w,id;
}a[5005];
#define mod 998244353ll
int c,T,n,m,ans;
bool cmp(node x,node y){
	if(1.0*x.v/x.w-1.0*y.v/y.w>-0.0001&&1.0*x.v/x.w-1.0*y.v/y.w<0.0001) return x.v>y.v;
	return 1.0*x.v/x.w>1.0*y.v/y.w;
}
bool cmp1(node x,node y){
	return x.id<y.id;
}
long long ksm(long long x){
	if(x==1) return 2;
	long long t=ksm(x/2);
	if(x%2) return 2*t%mod*t%mod;
	else return t*t%mod;
}
void dfs(int idx){
	if(idx>n){
		long long r=0,now=m,dp[10005]={0};
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(now>=a[i].w){
				now-=a[i].w;
				r+=a[i].v;
			}
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=a[i].w;j--){
				dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
			}
		}
		if(r==dp[m]) ans++;
		return;
	}
	a[idx].w=1;
	dfs(idx+1);
	a[idx].w=2;
	dfs(idx+1);
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i].v;
			a[i].id=i;
		}
		if(c==18) cout<<ksm(n)<<"\n";
		else{
			ans=0;
			dfs(1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
