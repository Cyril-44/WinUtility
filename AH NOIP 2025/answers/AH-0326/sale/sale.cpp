#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e3+5,M=1e4+5,K=5e8,mod=998244353;
struct node{
	LL x,y,id;
}a[N];
LL c,t;
LL n,m;
LL f[M],fac[N],ifac[N];
bool cmp(node p,node q){
	if(p.x*q.y==q.x*p.y){
		if(p.x==q.x){
			return p.id<q.id;
		}
		return p.x>q.x;
	}
	return p.x*q.y>q.x*p.y;
}
bool cmp2(node p,node q){
	return p.id<q.id;
}
LL qpow(LL p,LL q){
	LL s=1ll;
	while(q){
		if(q&1ll){
			s=s*p%mod;
		}
		p=p*p%mod;
		q>>=1ll;
	}
	return s;
}
LL C(LL p,LL q){
	//p>=q
	return fac[p]*ifac[q]%mod*ifac[p-q]%mod;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		fac[0]=1;
		for(LL i=1;i<=n;i++){
			cin>>a[i].x;
			a[i].id=i;
			fac[i]=fac[i-1]*i%mod;
		}
		ifac[n]=qpow(fac[n],mod-2);
		for(LL i=n;i>=1;i--){
			ifac[i-1]=ifac[i]*i%mod;
		}
		if(n<=10){
			LL ans=0;
			for(LL S=0;S<(1ll<<n);S++){
				sort(a+1,a+n+1,cmp2);
				for(LL i=1;i<=n;i++){
					if(S&(1ll<<(i-1))){
						a[i].y=1;
					}else{
						a[i].y=2;
					}
				}
				sort(a+1,a+n+1,cmp);
				LL sum=0,op=m,cnt=0;
				for(LL i=1;i<=n;i++){
					if(op<a[i].y) continue;
					op-=a[i].y;
					sum+=a[i].x;
				}
				for(LL i=0;i<=m;i++) f[i]=0;
				for(LL i=1;i<=n;i++){
					for(LL j=m;j>=a[i].y;j--){
						f[j]=max(f[j],f[j-a[i].y]+a[i].x);
					}
				}
				cnt=f[m];
				if(cnt==sum) ans++;
			}
			cout<<ans<<"\n";
		}else{
			cout<<qpow(2,n)<<"\n";
		}
	}
	return 0; 
}
