#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],L,R,q;
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	cin>>q;
	while(q--){
		cin>>L>>R;
		unsigned int ans=0,u=1;
		for(int i=1;i<=n;i++){
			int t=-1e18;
			for(int l=1;l<=n;l++){
				for(int r=l+L-1;r<=l+R-1;r++){
					if(i>=l&&r>=i)t=max(t,a[r]-a[l-1]);
				}
			}
			ans=(ans^(i*u*t));
		}
		cout<<ans<<"\n";
	}
    return 0;
}
