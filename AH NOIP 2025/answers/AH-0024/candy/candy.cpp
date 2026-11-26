#include<bits/stdc++.h>
#define int long long
#define ll long long
#define db double
#define ull unsigned long long
#define bint __int128
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
const int N=1e5+5;
int x[N],y[N];
int n; ll m;
int ida[N],idb[N];
bool cp1(int a,int b){
	return x[a]+y[a]<x[b]+y[b];
}
bool cp2(int a,int b){
	return x[a]<x[b];
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)ida[i]=i,idb[i]=i;
	sort(ida+1,ida+1+n,cp1);
	sort(idb+1,idb+1+n,cp2);
	int tp=ida[1],oc=x[tp]+y[tp];
	ll sum=0,ans=0;
	chkmax(ans,2*(m/oc));
	for(int i=1;i<=n;i++){
		sum+=x[idb[i]];
		chkmax(ans,(2*((m-sum)/oc))+i);
	}
	cout<<ans<<endl;
	return 0;
}
/*
code:
!noip@Nov29,2025:dream
*/
