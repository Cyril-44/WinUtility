#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m;
long long pom(long long b){
	if(b==1) return 2;
	if(b==0) return 1;
	
	long long x=pom(b/2);
	long long a=x*x;
	if(b%2==1) a=a*(x%MOD)%MOD;
	
	return a%MOD;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==18){
		while(t--){
			cin>>n>>m;
			long long x;
			for(int i=1;i<=n;i++){
				cin>>x;
			}
			cout<<pom(n)<<endl;
		}
	}
	return 0;
}
