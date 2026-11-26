#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())
#define pb push_back
#define fi first
#define se second


using namespace std;

typedef long long LL;

const int N=1e5+5;
int n;
LL m,x[N],y[N];


void solve(){
	cin>>n>>m;
	rep(i,1,n)cin>>x[i]>>y[i];
	LL z=1e18,ans=0,s=0;
	rep(i,1,n)z=min(z,x[i]+y[i]);
	sort(x+1,x+1+n);
	rep(i,0,n){
		if(i)s+=x[i];
		if(s<=m)ans=max(ans,i+(m-s)/z*2);
	}
	cout<<ans<<'\n';
}


int main(){

	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	int T=1;
	// cin>>T;
	while(T--)solve();

	return 0;
}
