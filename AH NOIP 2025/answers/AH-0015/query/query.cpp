#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=5e4+5;const long long inf=1e18;
int n,a[N],st[N],t,R[N],L[N],mk[N];long long s[N];
long long mx[N];vector<int>e[N];
inline void chmx(long long &u,long long v) {(u<=v&&(u=v));}
#define maxx(x,y) (x>y?x:y)
inline void upd(int x,long long y) {for(;x<=n;x+=(x&-x)) mx[x]=maxx(mx[x],y);}
inline long long query(int x) {long long rs=-inf;for(;x;x-=(x&-x)) rs=maxx(rs,mx[x]);return rs;}
vector<pair<long long,int> >pl[N];vector<int>ins[N];
inline void work() {
	int l1,r1;
	scanf("%d%d",&l1,&r1);
	fr(i,1,n) mx[i]=-inf,pl[i].clear(),mk[i]=0,ins[i].clear();
	fr(i,1,t) ins[st[i]].push_back(st[i]);
	int mxx=0;
	fr(r,l1,n) {
		int ll=max(1,r-r1+1),lr=r-l1+1;
		if(ll>1&&mk[ll-1]<r) {
			long long x=query(n+1-mk[ll-1]);
			pl[ll-1].push_back({x-s[ll-2],R[ll-1]});
		}
		if(ll>1) {
			for(int x:e[ll-1]) {
				if(x<=lr) {mk[x]=r;mxx=max(mxx,x);}
				else ins[x].push_back(x);
			}
		}
		for(int x:ins[lr]) {mk[x]=r;mxx=max(mxx,x);}
		upd(n+1-r,s[r]);
		pl[mxx].push_back({s[r]-s[mxx-1],r});mk[mxx]=r+1;
	}
	for(int i=n-r1+1;i<=n-l1+1;++i) if(R[i]<=n&&mk[i]&&mk[i]<=n) {
		long long x=query(n+1-mk[i]);
		pl[i].push_back({x-s[i-1],R[i]});
	}
	fr(i,1,n) mx[i]=-inf;
	unsigned long long ans=0;
	fr(i,1,n) {
		for(pair<long long,int>x:pl[i]) upd(n+1-x.second,x.first);
		ans^=((unsigned long long)query(n+1-i))*i;
	}
	printf("%llu\n",ans);
	return ;
}
int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	fr(i,1,n) scanf("%d",a+i),s[i]=s[i-1]+a[i];
	fr(i,1,n) R[i]=n+1;
	fr(i,1,n) {
		while(t&&s[st[t]-1]>=s[i-1]) {
			R[st[t]]=i-1;--t;
		}
		st[++t]=i;
	}
	t=0;
	rp(i,n,1) {
		while(t&&s[st[t]-1]>s[i-1]) {
			e[i].push_back(st[t]);--t;
		}
		st[++t]=i;
	}
	int q;scanf("%d",&q);
	while(q--) work();
	return 0;
}