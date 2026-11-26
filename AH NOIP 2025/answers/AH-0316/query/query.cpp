#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())
#define pb push_back
#define fi first
#define se second


using namespace std;


typedef unsigned long long ull;
const int N=3005;
ull ans[N][N],a[N];
ull st[N][N][20];
int bin[N],n;
ull query(int j,int l,int r){
	int k=bin[r-l+1];
	return max(st[j][l][k],st[j][r-(1<<k)+1][k]);
}

void solve(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,2,n)bin[i]=bin[i>>1]+1;
	rep(i,1,n){
		ull s=0;
		rep(j,i,n){
			s+=a[j];
			st[i][j][0]=s;
		}
		rep(j,1,13)rep(k,1,n-(1<<j)+1)st[i][k][j]=max(st[i][k][j-1],st[i][k+(1<<(j-1))][j-1]);
	}
	int q;cin>>q;
	while(q--){
		ull res=0;
		int l,r;cin>>l>>r;
		rep(i,1,n){
			ull v=0;
			rep(j,max(1,i-r+1),i){
				//st[j][i,j+r-1]
				int ll=max(i,min(i+l-1,n)),rr=min(n,j+r-1);
				if(ll<=rr){
					v=max(v,query(j,ll,rr));
				}
			}
			res^=((ull)i*v);
		}
		cout<<res<<'\n';
	}
}


int main(){

	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	int T=1;
	// cin>>T;
	while(T--)solve();

	return 0;
}
