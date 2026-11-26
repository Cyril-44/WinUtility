#include<iostream>
using namespace std;
const long long MOD=998244353;
int c,t;
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
		int n,m; cin>>n>>m;
		for(int i=1;i<=n;i++){
			int a; cin>>a;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%MOD;
		}
		cout<<ans<<endl;
	}
    return 0;
}
