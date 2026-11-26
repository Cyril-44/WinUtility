#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,x,l;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>l>>t;
    while(t--){
		int ans=1;
		cin>>n>>m;
		while(n--){
			ans*=2;
			ans%=998244353;
			cin>>x;
		}
		cout<<ans<<'\n';
    }
    return 0;
}
