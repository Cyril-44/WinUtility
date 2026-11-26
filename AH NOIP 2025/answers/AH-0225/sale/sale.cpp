#include<bits/stdc++.h>

using namespace std;
int c,t,a[1001];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,maxn=-1,m,ans=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		if(a[1]==a[2]&&a[3]==a[4]&&a[1]==a[3]){
			for(int i=1;i<=n;i++){
				ans*=2;
				ans=ans%998244353;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(m==2){
			for(int i=1;i<n;i++){
				ans*=2;
				ans=ans%998244353;
			}
			int x;
			sort(a+1,a+1+n,cmp);
			for(int i=2;i<n;i++){
				if(a[i]+a[1]>=maxn){
					x=i;
					break;
				}
			}
			maxn=1;
			for(int i=1;i<x;i++){
				maxn*=2;
				maxn=maxn%998244353;
			}
			cout<<maxn+ans<<"\n";
		}
	}
	return 0;
}
