#include <bits/stdc++.h>
using namespace std;
const long long MAXN=50+5,mod=998244353;
struct L{
	long long x,y;
};
bool cmp(L a,L b){
	if(a.y!=b.y){
		return a.y>b.y;
	}
	return a.x>b.x;
}
long long n,m,a[MAXN];
long long sum;
L o[MAXN];
long long ok(long long z){
	for(int i=0;i<n;i++){
		o[i+1].x=o[i+1].y=a[i+1];
		if(z&(1<<i)){
			o[i+1].y/=2;
		}
	}
	sort(o+1,o+1+n,cmp);
	long long s=m,q=0,q2=0;
	for(int i=1;i<=n;i++){
		if(s>=(o[i].x!=o[i].y)+1){
			s=s-(o[i].x!=o[i].y)-1;
			if(o[i].x==o[i].y){
				q2=q;
				q=o[i].x;
			}
			o[i].x=-1;
		}
	}
	if(q!=0){
		for(int i=1;i<=n;i++){
			if(o[i].x>q+q2){
				return 0;
			}
		}
	}
	return 1;
}
bool ok2(long long x){
	long long mi=1e10;
	for(int i=1;i<=n;i++){
		mi=min(mi,a[i]);
		if(a[i]<=a[x]/2){
			return 0;
		}
	}
	if(mi<a[x]){
		return 1;
	}
	return 0;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int y,t;
	cin>>y>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];a[i]*=2;
		}
		if(m==n*2-1){
			long long sum=1;
			for(int i=1;i<=n;i++){
				sum*=2;sum%=mod;
			}
			for(int i=1;i<=n;i++){
				if(ok2(i)){
					sum--;
				}
			}
			sum=(sum+mod)%mod;
		}
		sum=0;
		long long len=1<<n;
		for(int i=0;i<len;i++){
			if(ok(i)){
				sum++;sum%=mod;
			}
		}
		cout<<sum;
		if(t){
			cout<<'\n';
		}
	}
	return 0;
}
