#include <iostream>
#include <algorithm>
using namespace std;
const int N=5000,MOD=998244353;
int n,m,a[N+5],ans,l,r;
int c[N+5][N*2+5],p[N+5];
long long cur;
int add(int x,int y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}
int del(int x,int y){
	x-=y;
	if(x<0)x+=MOD;
	return x;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=N;++i)p[i]=add(p[i-1],p[i-1]);
	for(int i=1;i<=N;++i)p[i]=add(p[i-1],p[i]);	
	for(int i=0;i<=N;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j)
			c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	ios::sync_with_stdio(0);cin.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		a[n+1]=0;
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		ans=del(p[n],p[n-1]);
		for(int i=1;i<=n;++i)
			for(int j=i+1,k=n+1;j<=n&&2*a[j]>a[i];++j){
				if(a[j]==a[i])continue;
				while(a[j]+a[k-1]<a[i])--k;
				cur=(k==n+1?0:p[n-k])+1;
				cur=cur*c[j-2][m-i-1]%MOD;
				ans=del(ans,cur);
			}
		cout<<ans<<'\n';
	}
	return 0;
}

