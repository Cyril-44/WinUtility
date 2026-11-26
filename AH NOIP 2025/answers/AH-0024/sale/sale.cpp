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
#define debug(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
const int mod=998244353;
int fpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
	return res;
}
const int V=2e4+5,N=5e3+5;
int fac[V],ifac[V],pw[V];
void initfac(){
	fac[0]=1;
	for(int i=1;i<V;i++)fac[i]=fac[i-1]*i%mod;
	pw[0]=1;
	for(int i=1;i<V;i++)pw[i]=pw[i-1]*2%mod;
	ifac[V-1]=fpow(fac[V-1],mod-2);
	for(int i=V-2;~i;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
}
int C(int m,int n){
	if(m<0||n<0||m<n)return 0;
	return fac[m]*ifac[n]%mod*ifac[m-n]%mod;
}
int a[N];
struct Info{
	int v,w,id;
	bool operator<(const Info& t){
		if(v*t.w!=w*t.v)return v*t.w>w*t.v;
		if(v!=t.v)return v>t.v;
		return id<t.id;
	}
}b[N<<1];
int n,m;
int fp[N],sp[N];
int suf[N<<1];
int pre[N<<1];
inline int upd(int x){
	return (x>=mod)?(x-mod):x;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[2*i-1]=(Info){a[i],1,i};
	for(int i=1;i<=n;i++)b[2*i  ]=(Info){a[i],2,i};
	sort(b+1,b+1+2*n);
	for(int i=1;i<=2*n;i++)if(b[i].w==1)fp[b[i].id]=i;
	for(int i=1;i<=2*n;i++)if(b[i].w==2)sp[b[i].id]=i;
	int ans=0;
	suf[2*n+1]=0;
	for(int i=2*n;i;i--)suf[i]=suf[i+1]+(b[i].w==1);
	pre[0]=0;
	for(int i=1;i<=2*n;i++)pre[i]=pre[i-1]+(b[i].w==2);
	for(int i=1;i<=2*n;i++)if(b[i].w==2){
		int k=i;
		int ca=n-suf[i]-1,cb=pre[i]-1,cd=suf[i];
		for(int j=i-1;j && (ca+cb>=m-1);j--)if(b[j].w==1 && b[j].v<b[i].v){
			while((b[k].w==2||(b[k].v+b[j].v>=b[i].v))&&(k<=2*n)){
				cd-=(b[k].w==1);
				k++;
			}
			int u=b[j].id;
			int val=pw[cd];
			if(sp[u]!=i){
				if(sp[u]<i)ans+=val*C(ca-1,m-1-cb)%mod;
				if(sp[u]>i)ans+=val*C(ca-1,m-2-cb)%mod;
			}
			ans=upd(ans);
			if(sp[u]<i)ca--,cb++;
			if(sp[u]>i)ca--;
		}
	}
	
	cout<<(pw[n]-ans+mod)%mod<<endl;
}
int Testid,T;
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Testid>>T;
	initfac();
	while(T--)solve();
	return 0;
}
/*
code:
!noip@Nov29,2025:dream
0 1
3 2
1 3 5
*/
