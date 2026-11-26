#include<bits/stdc++.h>
using namespace std;
long long modd=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t,ans=1;
	cin>>c>>t;
	while(t--){
		long long n,m,a[5005];
		cin>>n>>m;
		for(int i=1;i<=n;i++){
		ans*=2;
		ans%=modd;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
			int ans1=1;
			int t=0;
			for(int i=1;i<=n;i++){
				if(a[i]*2>a[n]){
					t++;
				}
			}for(int i=1;i<=t;i++)ans1*=2%modd;
			ans1%=modd;
			ans-=ans1;
			cout<<ans;
	}
	return 0;
}
