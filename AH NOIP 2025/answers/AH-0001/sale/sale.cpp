#include<bits/stdc++.h>
using namespace std;
const int Maxn=5005,Mod=998244353;
int n,m,a[Maxn],C[Maxn][Maxn],ans,pw[Maxn];
void Add(int &a,int b){a+=b;if (a>=Mod) a-=Mod;}
bool cmp(const int &u,const int &v){return u>v;}
int cc(int n,int m){return n>=m&&m>=0?C[n][m]:0;}
void work(){
	scanf("%d%d",&n,&m);pw[0]=1;
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i) pw[i]=2ll*pw[i-1]%Mod;
	sort(a+1,a+1+n,cmp);ans=pw[n];
	for(int i=1;i<=n;++i) Add(pw[i],pw[i-1]);
	if (m==1){printf("%d\n",ans);return ;}
	for(int i=0;i<=n;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){C[i][j]=C[i-1][j-1];Add(C[i][j],C[i-1][j]);}
	}
	for(int i=1;i<=n;++i) for(int j=i+1,p=n+1;j<=n;++j) if (a[j]*2>a[i]){
		if (p<=j) p=j+1;
		while(p-1>j&&a[j]+a[p-1]<a[i]) --p;
		if (a[j]<a[i]){
			int ca=i-1,cb=j-i-1;
			Add(ans,Mod-cc(ca+cb,m-2-ca));
			if (p<=n) Add(ans,Mod-1ll*cc(ca+cb,m-2-ca)*pw[n-p]%Mod);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--) work();
	return 0;
}
