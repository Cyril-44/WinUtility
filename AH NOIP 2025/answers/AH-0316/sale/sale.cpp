#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())
#define pb push_back
#define fi first
#define se second


using namespace std;

typedef long long LL;

int qmi(int a,int b,int p){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%p;
		b>>=1;
		a=1ll*a*a%p;
	}
	return res;
}

const int N=100,mod=998244353;
int n,m,a[N],f[N];
struct Node{
	int id,w,v;
	bool operator<(const Node&W)const{
		if(v^W.v)return v>W.v;
		else return id<W.id;
	}
}b[N];
int get(){
	rep(j,0,m)f[j]=0;
	rep(i,0,n-1)per(j,m,b[i].w)f[j]=max(f[j],f[j-b[i].w]+2ll*a[b[i].id]);
	return f[m];
}

void solve(){
	cin>>n>>m;
	rep(i,0,n-1){
		cin>>a[i];
	}
	int ans=0;
	rep(i,0,(1<<n)-1){
		rep(j,0,n-1)b[j]=(Node){j,(!(i>>j&1))+1,(1+(i>>j&1))*a[j]};
		//0:/2,1:/1
		sort(b,b+n);
		int now=m,s=0;
		rep(j,0,n-1){
			if(now>=b[j].w){
				now-=b[j].w;
				s+=2ll*a[b[j].id];
			}
		}
		if(s==get()){
			++ans;
		}
	}
	cout<<ans<<'\n';
}


signed main(){

	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);


	int c,T=1;
	cin>>c>>T;
	while(T--)solve();

	return 0;
}
