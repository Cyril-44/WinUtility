#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,i,a[50009],w[50009],ct,cut;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
		ct=1;
		cut=1;
		cin>>n>>m;
		for(i=1;i<=n;i++)ct*=2;
		for(i=1;i<=abs(n-m);i++)cut*=2;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=2;i++)w[i]=i;
		cout<<(ct-cut)%998224353<<'\n';
	}
	return 0;
}
