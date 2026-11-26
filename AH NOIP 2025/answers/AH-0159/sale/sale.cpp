#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
int c,t,n,m,a[5005];
long long ans,jie[5005],niv[5005];
bool cmp(int x,int y){
	return x>y;
}
inline long long quick(long long a,long long x){
	long long s=1;
	while(x){
		if(x&1) s=s*a%mo;
		a=a*a%mo;
		x/=2;
	}
	return s;
}
inline long long C(int m,int n){
	return jie[n]*niv[m]%mo*niv[n-m]%mo;
}
int main(){
//	freopen("sale.in","r",stdin);
//	freopen("sale.out","w",stdout);
	cin>>c>>t;
	jie[0]=niv[0]=1;
	for(int i=1;i<=5000;i++) jie[i]=jie[i-1]*i%mo,niv[i]=quick(jie[i],mo-2);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		int pl=2;
		for(int i=1;i<=n;i++){
			while(a[pl]>a[i]/2&&pl<n) pl++;
			cout<<pl<<endl;
			if(pl>=m&&(pl-1-m)%3==0&&pl>i+1){
				int pl1=pl;
				for(int j=pl-1;j>=1;j--){
					if(j==i) break;
					while(a[pl1]+a[j]>=a[i]&&pl1<=n) pl1++;
					if(pl1>n) break;
					ans=(ans+C(pl-i-2,pl-i-1)*quick(2,1ll*(n-pl1+1))%mo)%mo;
				}
			}
		}
		cout<<ans<<endl;
	/*	ans=quick(2,n)-ans;
		while(ans<0) ans+=mo;
		cout<<ans<<endl;*/
	}
}
