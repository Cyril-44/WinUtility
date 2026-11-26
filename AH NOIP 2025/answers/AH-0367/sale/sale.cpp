#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 998244353;
const int N = 5e3+5;
ll a[N],c,t,n,m,k,w1,w2,ans,lost;
ll p2(ll x){return x*x%mod;}
ll qpow(ll a,ll b){
	if(b==0)return 1LL;
	if(b==1)return a%mod;
	if(b&1)return qpow(a,b-1)*a%mod;
	else return p2(qpow(a,b>>1));
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;//c=18;
	while(t--){
		cin>>n>>m;
		lost=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==18||c==16||c==10||c==11||c==12||c==19||c==20)ans=qpow(2,n);
		else if(c==17){
			sort(a+1,a+1+n);
			if(a[1]*2>a[2]&&a[1]!=a[2])lost=1;
			ans=(qpow(2,n)+mod-lost)%mod;
		}
		else if(c==7||c==8||c==9||c==14||c==15){
			sort(a+1,a+1+n);
			w1=upper_bound(a+1,a+1+n,a[n]/2.0)-a;
			for(int j=w1;j<n;j++){
				w2=lower_bound(a+1,a+1+n,a[n]-a[j])-a-1;
				lost=(lost+qpow(2,w2))%mod;
			}
			ans=(qpow(2,n)+mod-lost)%mod;
			/*
			cout<<a[n]<<' '<<a[n-1]<<' '<<a[n-2]<<'\n';
			if(a[n]<2*a[n-1]&&2*a[n-2]<a[n]){
				//cout<<"win\n";
				w=lower_bound(a+1,a+1+n,a[n]-a[n-1])-a-1;
				ans=(qpow(2,n)+mod-qpow(2,w)+1)%mod;
			}*/
		}
		cout<<ans<<'\n';
	}
    return 0;
}
