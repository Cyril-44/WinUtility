#include<bits/stdc++.h>
using namespace std;
#define ll long long
int qm=998244353,ans=1,a[10005],b[100005],c[100005];
int main(){
		int n,m,c,t;
		freopen("sale.in","r",stdin);
		freopen("sale.out","w",stdout);
		cin>>c>>t;
		for(int i=1;i<=t;i++){
			ll pf=1;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(i>=2 && a[i]==a[i-1]) pf++;
			}
			if(pf==n) {
				while(pf>0){
					ans*=2;
					pf--;
				}
				cout<<ans<<endl;
				return 0;
			}
		return 0;
		}
}
