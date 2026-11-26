#include<bits/stdc++.h>
using namespace std;
int a[3005];
int n,q;
int ans[3005];
int tmp[3005];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	while(q--){
		int l,r; cin>>l>>r;
		memset(ans,-0x3f,sizeof(ans));
		int sum=0;
		for(int i=1;i<=n;i++){
			memset(tmp,-0x3f,sizeof(tmp));
			for(int j=i;j<=n;j++){
				sum+=a[j];
				if(j-i+1>=l&&j-i+1<=r){
					tmp[j]=sum;
				}
			}
			for(int j=n-1;j>=i;j--) if(tmp[j]!=-0x3f3f3f3f) tmp[j]=max(tmp[j],tmp[j+1]);
			for(int j=n;j>=i;j--) ans[j]=max(ans[j],tmp[j]);
		}
		unsigned long long anss=0;
		for(int i=1;i<=n;i++) cout<<ans[i]<<' '; cout<<'\n';
		for(int i=1;i<=n;i++) anss^=1ull*i*ans[i];
		cout<<anss<<'\n';
	}
	return 0;
}