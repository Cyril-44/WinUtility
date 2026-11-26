#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define req(i,a,b) for(int i=a;i>=b;--i)
const int N=50005;
int a[N];ll s[N],st[N][16];int n,q;
ull res[N];
ll query(int l,int r){
	int d=__lg(r-l+1);
	return min(st[l][d],st[r-(1<<d)+1][d]);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i],st[i][0]=s[i];
	rep(j,1,15){
		rep(i,0,n-(1<<j)+1){
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	} 
	cin>>q;
	if(q==1){
		int l,r;cin>>l>>r;
		ull ans=0;
		rep(i,1,n){
			ll res1=-0x3f3f3f3f3f3f3f3fll;
			int lim=min(n,i+r-1);
			for(int j=max(l,i);j<=lim;++j){
				res1=max(res1,s[j]-query(max(j-r+1-1,0),min(j-l+1-1,i-1)));
			}
			ans^=(ull)(i)*(ull)res1;
		} cout<<ans<<'\n';
		return 0;
	} 
	rep(i,1,q){
		int l,r;cin>>l>>r;
		ull ans=0;
		rep(i,1,n){
			ll res1=-0x3f3f3f3f3f3f3f3fll;
			int lim=min(n,i+r-1);
			for(int j=max(l,i);j<=lim;++j){
				res1=max(res1,s[j]-query(max(j-r+1-1,0),min(j-l+1-1,i-1)));
				// cout<<j<<' ';
			}
			// cout<<res1<<'\n';
			ans^=(ull)(i)*(ull)res1;
		} cout<<ans<<'\n';
	}
	return 0;
}
