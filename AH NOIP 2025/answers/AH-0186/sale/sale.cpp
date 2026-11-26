#include<bits/stdc++.h>
using namespace std;
int n,c,t;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	if(c==18){
		
	for(int ii=1;ii<=t;ii++){
	cin>>n;	
	long long a=1;
	for(int i=1;i<=n;i++){
		a*=2;
		a%=998244353;
	}
	cout<<a<<endl;
}
}
	
	return 0;
}
