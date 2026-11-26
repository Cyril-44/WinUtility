#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}
