#include<bits/stdc++.h>
using namespace std;
long long c,t;
int a[5010];
long long ans=0,n,m;
long long P=998244353;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(m==2*n-1){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*2%P;
			}
			cout<<ans;
		}
		else if(m==2*n-2){
			sort(a+1,a+n+1);
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*2%P;
			}
			if(a[1]*2>a[2]&&a[1]<a[2]){
				ans--;
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}
