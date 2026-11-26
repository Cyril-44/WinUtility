#include "bits/stdc++.h"
using namespace std;
const int N=10005,mod=998244353;
int a[N],n,m,Ans,pw2[N];
int fac[N],ifac[N];
void add(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int add1(int x,int y){return x+y<mod?x+y:x+y-mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
int ksm(int x,int y){int res=1;for(;y;y>>=1,x=mul(x,x))if(y&1)res=mul(x,res);return res;}
int binom(int x,int y){
	if(x<y||x<0||y<0)return 0;
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
int f(int A,int B){return binom(A-2,m-1-B);}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	a[n+1]=0;
}
void work(){
	Ans=pw2[n];
	if(m==1){printf("%d\n",Ans);return;}
	int A,B,C;
	for(B=1;B<=n;B++){
		for(A=B+1;A<=n&&(a[A]<<1)>a[B];A++);
		A--;C=A+1;for(;a[C]+a[A]>=a[B]&&C<=n;C++);
		for(;A>B;A--){
			for(;C<=n&&a[C]+a[A]>=a[B];C++);
			int vr=pw2[n-C+1],vl=f(A,B);
			if(a[A]==a[B])vr=add1(vr,mod-1);
			Ans=add1(Ans,mod-mul(vl,vr));
		}
	}
	printf("%d\n",Ans);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	fac[0]=ifac[0]=1;
	for(int i=1;i<N;i++)fac[i]=mul(fac[i-1],i);
	ifac[N-1]=ksm(fac[N-1],mod-2);
	for(int i=N-2;i;i--)ifac[i]=mul(ifac[i+1],i+1);
	pw2[0]=1;for(int i=1;i<N;i++)pw2[i]=mul(pw2[i-1],2);
	int Tid=0,T=0;
	scanf("%d%d",&Tid,&T);
	while(T--){
		init();
		work();
	}
	return 0;
}