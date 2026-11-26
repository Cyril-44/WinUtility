/*
cd ~/draft && g++ 21.cpp -std=c++14 -O2 -Wall -o 21
cd ~/draft && g++ 21.cpp -std=c++14 -O2 -Wall -o 21 && ./21
*/
#include <bits/stdc++.h>
#define debug(x) cout<<"In Function "<<__FUNCTION__<<",Line "<<__LINE__<<","<<#x<<":"<<x<<"."<<endl;
#define cputime printf("CPU time used:%.3f.\n",(double)clock()/CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);++a)
#define low(a,b,c) for(a=(b);a>=(c);--a)
using namespace std;
typedef long long var;

const int N=1e6+10;
const var mod=998244353;
const int INF=0x7fffffff;
const long long INFll=0x7fffffffffffffff;
const unsigned long long INFull=0xffffffffffffffff;

var c,t,n,m,a[N];

var fpow(var x,var y,var z){
	var res=1;
	while(y){
		if(y&1){res=res*x%mod;}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void code(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	var i;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		upp(i,1,n){
			cin>>a[i];
		}
		cout << fpow(2,n,mod) << endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	code();
	return 0;
} 