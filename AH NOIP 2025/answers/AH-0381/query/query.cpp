#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[50010],q;
int s[50010];
int ans[50010];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+s[i];
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		for(int i=1;i<=n;i++){
		ans[i]=-1000000000;
			for(int j=i-l;j<=i;j++){
				for(int k=l;k<=r&&k+j<=n;k++){
					ans[i]=max(ans[i],s[k+j]-s[j-1]);
				}
			}
		}
		unsigned long long t=0;
		for(int i=1;i<=n;i++)t=t^(ans[i]*i);
		cout<<t<<'\n';
	}
	return 0;
}
