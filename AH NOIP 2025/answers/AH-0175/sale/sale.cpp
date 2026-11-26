#include<bits/stdc++.h>
#define ll long long
//!noip@Nov29,2025:dream
using namespace std;
const int M=5e4+10,mod=998244353,N=1e7+10;
int n,m;
ll sum;
ll qpow(ll inin,ll base){
	ll res=1;
	for(;base;base>>=1){
		if(base&1) res=res*inin%mod;
		inin=inin*inin%mod;
	}
	return res%mod;
}
struct Candy{
	ll a,w,l;int i;
	bool operator<(const Candy &x)const{
		if(l==x.l){
			if(a==x.a) return i<x.i;
			else return a<x.a;
		}
		else return l<x.l;
	}
	bool operator<=(const Candy &x)const{
		if(l==x.l){
			if(a==x.a) return i<=x.i;
			else return a<=x.a;
		}
		else return l<=x.l;
	}
}a[M];
int main(){
	int t,c;
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int i;sum=0;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i].a;
			a[i].i=i;
			a[i].w=2;
			a[i].l=a[i].a;
		}
		sort(a+1,a+n+1);
		//for(i=1;i<=n;i++) cout<<a[i].a<<" ";
		//cout<<endl;
		for(i=n-1;i>=1;i--){
			a[i].l*=2;
			int l=i+1,r=n,res=-1;
			while(l<=r){
				int mid=l+((r-l)>>1);
				if(a[mid]<a[i]){
					res=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			//cout<<res<<endl;
			if(res>=n-(2*n-m)/2+1){
				sum=(sum+qpow(2,i-1))%mod;
			}
			a[i].l/=2;
		}
		cout<<(qpow(2,n)-sum+mod)%mod<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
