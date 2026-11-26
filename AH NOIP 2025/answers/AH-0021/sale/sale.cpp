#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=1e5;
const int mod=998244353;
int n,m,cost,a[N],ans=0,al=0,no=0,c,T,to[N];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
long long fac[N],ifac[N],pw2[N];
long long ksm(long long p,int q){
	long long ans=1;
	while(q){
		if(q&1)ans=ans*p%mod;
		p=p*p%mod,q>>=1;
	}
	return ans;
}
long long get_c(int x,int y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	fac[0]=ifac[0]=pw2[0]=1;
	for(int i=1;i<=M;i++)fac[i]=fac[i-1]*i%mod,pw2[i]=pw2[i-1]*2%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	scanf("%d%d",&c,&T);

	// printf("%d\n",T);

	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ans=pw2[n];
		if(m==1){
			printf("%d\n",ans);
			continue;
		}

		// for(int i=1;i<=n;i++)printf("%d ",a[i]);
		// printf("\n\n");

		int fir=1;
		for(int i=1;i<=n;i++){
			int lim=a[i]*2;
			while(fir<=n&&lim>a[fir])fir++;
			to[i]=fir-1;
			// printf("%d %d\n",i,to[i]);
		}
		for(int i=1;i<=n;i++){
			if(to[i]==i)continue;
			int pos=i-1;
			for(int j=to[i];j>i;j--){
				int res=m-2-(n-j);
				int R=n-i-1;
				// printf("?%d %d %d %d\n",i,j,res,R);
				if(res<0||R<res)continue;
				long long g=get_c(R,res);
				int lim=a[j]-a[i];
				// printf("!!%d %lld\n",lim,g);
				if(lim==0)continue;
				while(pos&&a[pos]>=lim)pos--;
				// printf("????%lld\n",pw2[pos]*g);
				add(ans,mod-pw2[pos]*g%mod);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
O(N*n),足以通过
*/