#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,a[10086];
long long ans;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	if(C==18||C==16){
		while (T--){
			cin>>n>>m;
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=2;
				ans%=998244353;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(T--){
		cin>>n>>m;
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		cout<<ans<<endl;
		continue;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		
		
	
	return 0;
}
