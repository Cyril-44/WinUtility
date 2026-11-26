#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=1e18;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int N=100005;
int n,m;
pii a[N];
void solve(){
	cin>>n>>m;
	int mn=INF;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi>>a[i].se;
		mn=min(mn,a[i].fi+a[i].se);
	}
	sort(a+1,a+n+1,[](pii x,pii y){return x.fi<y.fi;});
	int ans=(m/mn)*2;
	int s=0;
	for(int i=1;i<=n;i++){
		s+=a[i].fi;
		if(m<s)break;
		ans=max(ans,((m-s)/mn*2)+i);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
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
