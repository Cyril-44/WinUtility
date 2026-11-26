//long long  freopen 多测
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=5010;
int n,q,a[N];
int sum[N];
int f[N][N];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	memset(f,0xcf,sizeof(f));
	for(int l=1;l<=n;l++){
		int cnt=0;
		for(int len=1;len<=n&&l+len-1<=n;len++){
			cnt+=a[l+len-1];
			for(int i=l;i<=l+len-1;i++){
				f[i][len]=max(f[i][len],cnt);
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
	//	cout<<endl;
	//}
	cin>>q;
	for(int i=1,l,r;i<=q;i++) {
		ull ans=0;
		cin>>l>>r;
		for(int j=1;j<=n;j++){
			int mx=-1e13;
			for(int len=l;len<=r;len++){
				mx=max(mx,f[j][len]);
			}
			ans=ans^(1ull*j*mx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
