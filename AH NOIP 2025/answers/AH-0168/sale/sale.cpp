#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
int a[10001];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m<=n){
		long long ans=1;
		for(int i=n;i>=n-m+1;i--){
			ans=ans*i%mod;
		}
		for(int i=m-1;i>=1;i--){
			ans=(ans/i+mod)%mod;
		}
		for(int i=1;i<=n-m;i++){
			ans=ans*2%mod;
		}
		printf("%lld",ans);
	}
	else{
		long long ans=1;
		for(int i=n;i>=2*n-m+1;i--){
			ans=ans*i%mod;
		}
		for(int i=2*n-m-1;i>=1;i--){
			ans=(ans/i+mod)%mod;
		}
		for(int i=1;i<=m-n;i++){
			ans=ans*2%mod;
		}
		printf("%lld",ans);
	}
	return 0;
}
