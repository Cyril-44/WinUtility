#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=5005,mod=998244353;
int cc,T,n,a[N],m,to[N],c[N][N],ans,pw2[N];
inline void ad(int &u,int v) {u+=v;(u>=mod&&(u-=mod));}
inline void work() {
	scanf("%d%d",&n,&m);ans=0;
	fr(i,1,n) scanf("%d",a+i);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);a[n+1]=0;
	fr(i,1,n) {
		if(m-i+1<2) continue;
		for(int j=i+1,k=n+1;j<=n&&a[j]*2>a[i];++j) {
			while(a[j]+a[k-1]<a[i]) --k;
			if(a[j]<a[i]&&m-i-1<=j-2) ad(ans,c[j-2][m-i-1]*1ll*pw2[n-max(j+1,k)+1]%mod);
		}
	}
	printf("%d\n",(pw2[n]-ans+mod)%mod);
	return ;
}
int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&cc,&T);
	fr(i,0,5000) {
		c[i][0]=1;
		fr(j,1,i) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	pw2[0]=1;fr(i,1,5000) pw2[i]=pw2[i-1]*2%mod;
	while(T--) work();
	return 0;
}