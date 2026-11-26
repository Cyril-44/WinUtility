#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fast_power(ll, ll);
int main(){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	int t, c;
	cin>>c>>t;
	for(int i = 0 ; i < t ; i++){
		ll n, m;
		ll a[5005];
		cin>>n>>m;
		for(int j = 0 ; j < n ; j++){
			cin>>a[j];
		}
		cout<<(fast_power(2, n) % 998244353)<<endl;
	}
	
	
	return 0;
}

ll fast_power(ll a, ll b){
	ll ans = 1;
	for(;b;b = b>>1){
		if(b % 2){
			ans *= a;
		}
		a *= a;
		a %= 998244353;
		//ans *= a;
		ans %= 998244353;
		cout<<a<<' '<<ans<<endl;
	}
	//ans *= a;
	return ans;
}
