#include<bits/stdc++.h>
#define ll long long
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const int MAXN=1e5+10;
int n;
ll m,x[MAXN],y[MAXN];

int main() {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	ll mn=LONG_LONG_MAX,res=0;
	ffor(i,1,n) cin>>x[i]>>y[i],mn=min(mn,x[i]+y[i]);

	vector<ll> vc;
	ffor(i,1,n) vc.push_back(x[i]);
	sort(vc.begin(),vc.end());

	ll tmp=0;
	ffor(i,0,n) {
		if(i) tmp+=vc[i-1];
		if(tmp<=m) res=max(res,i+2*((m-tmp)/mn));
	}
	cout<<res;
	return 0;
}