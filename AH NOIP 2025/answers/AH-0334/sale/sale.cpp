#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
const double eps=1e-8;
int a[N],id[N],w[N];
long long dp[N];
double myabs(double x){return ((x>0)?x:-x);}
bool cmp(int x,int y){
	if(myabs(1.0*a[x]/w[x]-1.0*a[y]/w[y])<eps) return a[x]>a[y];
	else return 1.0*a[x]/w[x]>1.0*a[y]/w[y];
}
int kpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=(1ll*ans*a)%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,m,zans=0;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(1<=c&&c<=5){
			for(int i=0;i<(1<<n);i++){
				long long now=0,m2=m,ans=0;
				for(int j=0;j<n;j++) w[j+1]=((i>>j)&1)+1;
				for(int j=1;j<=n;j++) id[j]=j;
				sort(id+1,id+n+1,cmp);
				for(int j=1;j<=n;j++){
					if(m<w[id[j]]) continue;
					now+=a[id[j]];m-=w[id[j]];
				}
				for(int j=1;j<=n;j++){
					for(int k=0;k<=m2-w[j];k++){
						dp[k]=max(dp[k],dp[k+w[j]]+a[j]);
					}
				}
				for(int j=0;j<=m2;j++) ans=max(ans,dp[j]),dp[j]=0;
				if(ans==now) zans++;
				m=m2;
			}
			cout<<zans<<'\n';
		}
		if((7<=c&&c<=9)||(14<=c&&c<=15)){
			sort(a+1,a+n+1);long long zans=0;
			for(int i=n-1;i>=1;i--){
				if(2*a[i]<=a[n]) break;
				int now=i;
				for(;now>=1;now--) if(a[now]+a[i]<a[n]) break;
				zans=(zans+kpow(2,now))%mod;
			}
			cout<<(kpow(2,n)-zans+mod)%mod<<'\n';
		}
		if(c==18){
			cout<<kpow(2,n)<<'\n';
		}
		if(c==19||c==20){
			cout<<kpow(2,n)<<'\n';
		}
	}
	return 0;
}
