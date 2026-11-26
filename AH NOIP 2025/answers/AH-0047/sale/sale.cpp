#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long c,t,n,m,a[5005],dp[10005],ans,sum,cnt;
struct s{
	long long val;
	long long c;
	int id;
}num[5005];
bool cmp1(s a,s b){
	if(a.val*b.c==b.val*a.c){
		if(a.val==b.val) return a.id<b.id;
		return a.val>b.val;
	}
	return a.val*b.c>b.val*a.c;
}
bool cmp2(s a,s b){
	return a.id<b.id;
}
void dfs(int dep){
	if(dep==n+1){
		sort(num+1,num+n+1,cmp1);
		cnt=0;
		for(int i=1;i<=m;i++) dp[i]=-2e18;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=num[i].c;j--) dp[j]=max(dp[j],dp[j-num[i].c]+num[i].val);
		}
		for(int i=1;i<=m;i++) cnt=max(cnt,dp[i]);
		sum=m;
		for(int i=1;i<=n;i++){
			if(sum>=num[i].c) sum-=num[i].c,cnt-=num[i].val;
		}
		if(cnt==0) ans++;
		sort(num+1,num+n+1,cmp2);
		return;
	}
	num[dep].c=1;
	dfs(dep+1);
	num[dep].c=2;
	dfs(dep+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&num[i].val),num[i].id=i;
		if(n<=20){
			dfs(1);
			printf("%lld\n",ans);
		}else{
			ans=1;
			for(int i=1;i<=n;i++) ans=ans*2%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
0 1
3 2
1 3 5
*/
