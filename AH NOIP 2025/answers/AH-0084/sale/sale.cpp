#include<bits/stdc++.h>
using namespace std;
#define mod(x) x%998244353
#define N 5010
int n,m;
int sz[N],w[N],db[N];
long long qpow(long long x,long long y){//x^y
	if(x==0) return 0;
	if(x==1) return 1;
	if(y==1) return x;
	if(y==0) return 1;
	long long hfy=y/2;
	long long m=mod(qpow(x,hfy));
	long long ans=mod(m*m);
	if(y%2) ans*=x;
	return mod(ans);
}
void jg(int c){
	memset(sz,0,sizeof(sz));
	memset(w,0,sizeof(w));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
/*	
	cout<<qpow(2,n)<<endl;
	if(c==0) fun1();
	if(c==18) fun1();
	if(c==10 || c==11 || c==12 || c==19 || c==20) fun2();
	if(c==16) fun3();
	if(c>=7 && c<=9) fun4();
*/
}
int main(){


	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int potato=0;potato<t;potato++){
		jg(c);
	}
	return 0;
}
