#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ull unsigned long long
using namespace std;
const int INF=1e18;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int N=50005;
int n;
int a[N],s[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	int q;
	cin>>q;
	while(q--){
		ull ans=0;
		int l,r;
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			int res=-INF;
			for(int j=1;j<=i;j++){
				for(int k=max(i,l+j-1);k<=min(r+j-1,n);k++){
					res=max(res,s[k]-s[j-1]);
				}
			}
			ans^=(ull)(i*res);
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase=1,multitest=0;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve();
	}
	return 0;
}
