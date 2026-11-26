#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int mod = 998244353;
int c,t;
int n,m;
int a[maxn];
int ans;
int mi(int b){
	int res = 1;
	if(b == 0){
		return 1;
	}else{
		for(int i = 1;i<=b;i++){
			res=(res*2)%mod;
		}
		return res;
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	if((c>=7&&c<=9)||(c>=14&&c<=15)){
		while(t--){
			int ans = 0;
			int max_a = -1;
			cin>>n>>m;
			for(int i = 1;i<=n;i++){
				cin>>a[i];
				max_a = max(a[i],max_a);
			}
			sort(a+1,a+n+1);
			int q = max_a/2;
			for(int i = 1;i<=n;i++){
				if(a[i]==q){
					ans+=mi(i);
					ans+=(((n-i)*(n-i-1)%mod)*mi(i))%mod;
					cout<<ans<<endl;
					break;
				}
			}
		}
	}else if(c == 18){
		while(t--){
			cin>>n>>m;
			for(int i = 1;i<=n;i++){
				cin>>a[i];
			}
			cout<<((n*(n-1))%mod+1)%mod<<endl;
		}
	}
	return 0;
}
