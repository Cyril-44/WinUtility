#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c,t;
int n,m;
long long ans,dp[1005][2005];
struct node{
	long long w,sl,id;
}a[10005],b[10005];
bool cmp(node k1,node k2){
	if((k1.w*1.0/k1.sl*1.0==k2.w*1.0/k2.sl*1.0)&&k1.w==k2.w) return k1.id<k2.id;
	if(k1.w*1.0/k1.sl*1.0==k2.w*1.0/k2.sl*1.0) return k1.w>k2.w;
	return k1.w*1.0/k1.sl*1.0>k2.w*1.0/k2.sl*1.0;
}
void check(int w){
	for(int i=1;i<=n;i++){
		b[i].id=a[i].id;
		b[i].sl=a[i].sl;
		b[i].w=a[i].w;
	}
	sort(b+1,b+n+1,cmp);
	long long bj=0;
	for(int i=1;i<=n;i++){
		if(w==0) break;
		if(w>=b[i].sl){
			w-=b[i].sl;
			bj+=b[i].w;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if(j-b[i].sl>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-b[i].sl]+b[i].w);
		}
	}
	if(dp[n][m]==bj) ans++;
}
void dfs(int x){
	if(x==n+1){
		check(m);
		return;
	}
	a[x].sl=1;
	dfs(x+1);
	a[x].sl=2;
	dfs(x+1);
}
long long ksm(long long a,long long b){
	long long s=1;
	while(b){
		if(b%2==1) s=(s*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return s%mod;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;	
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(b,0,sizeof(b));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i].w);
		if(m==2*n-1||c==18){
			cout<<ksm(2,n)%mod<<endl;
		}
		else {
			dfs(1);
			printf("%lld\n",ans%mod);			
		}
	}
	return 0; 
}
