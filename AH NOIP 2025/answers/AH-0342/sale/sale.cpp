#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long mod=998244353;
long long p[5003];
int a[5003];
bool cmp(int x,int y){
	return x>y;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	return;
}
int find(int x){
	int l=0,r=n+1,mid;
	while(l<r-1){
		mid=(l+r)/2;
		if(a[mid]>x){
			l=mid;
		}else{
			r=mid;
		}
	}
	return r;
}
long long c(long long n,long long m){
	return (2+n*(m-1))*(n+1)/2;
}
void work(){
	long long sum=0,tmp;
	for(int i=1;i<n;i++){
		int tt=find(a[i]/2);
		int ta=i-1;
		int tb=tt-i-1;
		if((ta*2+tb*2-1)<m-1)continue;
		if((ta+tb)>m-1)continue;
		long long t2=m-1-ta-tb;
		long long t1=ta+tb-t2;
		tmp=c(t1,t2);
		tmp%=mod;
		tmp-=max(0ll,c(t2-tb,t1)%mod);
		tmp+=mod;
		tmp%=mod;
		tmp*=p[n-tt+1];
		tmp%=mod;
		sum+=tmp;
		sum%=mod;
	}
	printf("%lld\n",(p[n]-sum+mod)%mod);
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int t=1,c;
	scanf("%d",&c);
	scanf("%d",&t);
	p[0]=1ll;
	for(int i=1;i<=5002;i++){
		p[i]=p[i-1]*2;
		p[i]%=mod;
	}
	while(t--){
		init();
		work();
	}
	return 0;
}
