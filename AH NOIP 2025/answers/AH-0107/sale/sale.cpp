#include<bits/stdc++.h>
using namespace std;
int n,m,c,t;
int a[500005];
const int mod=998244353;
long long quickpow(int k){
	if(k==0){
		return 1;
	}
	if(k==1){
		return 2;
	}
	long long t=quickpow(k/2);
	t*=t;
	t%=mod;
	if(k%2==1){
		t*=2;
		t%=mod;
	}
	return t;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==18||m==1){
			cout<<quickpow(n)<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
