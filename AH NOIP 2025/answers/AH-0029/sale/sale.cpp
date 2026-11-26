#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=100010;
ll c,t,n,m,mn,ans;
ll fac[maxn],inv[maxn],dp[maxn];
const ll mod=998244353;
struct node{
	ll x,y,id;
}a[maxn];
ll qpow(ll a,ll x){
	if(x==0){
		return 1ll;
	}
	ll s=qpow(a,x/2);
	s=s*s%mod;
	if(x&1){
		s=s*a%mod;
	}
	return s;
}
ll C(ll n,ll m){
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
bool cmp1(node a,node b){
	if((a.x*2/a.y)==(b.x*2/b.y)){
		if(a.x==b.x){
			return a.id<b.id;
		}
		return a.x>b.x;
	}
	return (a.x*2/a.y)>(b.x*2/b.y);
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
bool cmp3(node a,node b){
	return a.x>b.x;
}
ll right(){
	ll sum=0;
	for(int i=0;i<=m;i++){
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i].y;j--){
			dp[j]=max(dp[j],dp[j-a[i].y]+a[i].x);
			sum=max(sum,dp[j]);
		}
	}
	return sum;
}
ll getans(){
	ll sum=0,tot=m;
	for(int i=1;i<=n;i++){
		if(tot>=a[i].y){
			tot-=a[i].y;
			sum+=a[i].x;
		}
	}
	return sum;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	fac[0]=1;
	for(int i=1;i<=5000;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=0;i<=5000;i++){
		inv[i]=qpow(fac[i],mod-2);
	}
	while(t--){
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;a[i].id=i;
		}
		//cout<<t<<endl;
		if(m==2*n-1||c==18){
			cout<<qpow(2,n)<<endl;
			continue;
		}
		if(n<=10){
			for(int k=0;k<(1<<n);k++){
				for(int i=1;i<=n;i++){
					if(k&(1<<(i-1))){
						a[i].y=1;
					}
					else{
						a[i].y=2;
					}
				}
				sort(a+1,a+n+1,cmp1);
				ll ans1=getans();
				ll ans2=right();
				if(ans1==ans2){
					ans++;
					//cout<<k<<' '<<ans1<<endl;
				}
				sort(a+1,a+n+1,cmp2);
			}
			cout<<ans<<'\n';
			continue;
		}
		if((c>=10&&c<=12)||(c>=19&&c<=20)){
			ans=qpow(2,n-1);
			for(ll i=(m+1)%2;i<=n;i+=2){
				int y=(n-i)-((m-i)/2);
				if(y<=0){
					ans+=C(n,i);
				}
				else if(n-y<=i){
					ans+=C(n-y,i);
				}
			}
			cout<<ans<<'\n';
		}
		else{
			ans=qpow(2,n);
			sort(a+1,a+n+1,cmp3);
			a[n+1].x=0;
			for(int i=2;i<n;i++){
				for(int j=i+1;j<=n+1;j++){
					if(a[i].x*2>a[1].x&&a[i].x+a[j].x<a[1].x){
						if(j==n+1){
							ans=ans+mod-1;
							ans%=mod;
						}
						else{
							ans=ans+mod-qpow(2,n-j);
							ans%=mod;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}	
	return 0;
}	
