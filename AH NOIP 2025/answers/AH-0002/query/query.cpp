#include<bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;

const int MAXN=5e4+10;

int n,q,a[MAXN];
ll pre[MAXN],Pre[MAXN],tmp[MAXN],res[18][18][MAXN];

inline void output(void) {
	unsigned ll ans=0;
	ffor(i,1,n) ans^=(unsigned ll)(tmp[i])*i;
	cout<<ans<<'\n';
	return ;
}
int hd,tl,Hd,Tl;
pair<ll,ll> dq[MAXN],Dq[MAXN];
inline void solve(const int l,const int r) {
	hd=1,tl=0,Hd=1,Tl=0;
	roff(i,n-l+1,1) {
		while(hd<=tl&&pre[i+l-1]>=dq[tl].first) tl--;
		dq[++tl]=make_pair(pre[i+l-1],i+l-1);
		while(hd<=tl&&dq[hd].second>i+r-1) hd++;
		ll mx=dq[hd].first-pre[i-1];

		while(Hd<=Tl&&mx>=Dq[Tl].first) Tl--;
		Dq[++Tl]=make_pair(mx,i);
		while(Hd<=Tl&&Dq[Hd].second>i+l-1) ++Hd;
		tmp[i+l-1]=max(tmp[i+l-1],Dq[Hd].first);
	}
	ll v=0;
	roff(i,l-1,1) {
		while(Hd<=Tl&&Dq[Hd].second>i) ++Hd;
		if((v=Dq[Hd].first)>tmp[i]) tmp[i]=v;
	}
	return ;
}
inline void Solve(const int l,const int r) {
	hd=1,tl=0,Hd=1,Tl=0;
	roff(i,n-l+1,1) {
		while(hd<=tl&&Pre[i+l-1]>=dq[tl].first) tl--;
		dq[++tl]=make_pair(Pre[i+l-1],i+l-1);
		while(hd<=tl&&dq[hd].second>i+r-1) hd++;
		ll mx=dq[hd].first-Pre[i-1];

		while(Hd<=Tl&&mx>=Dq[Tl].first) Tl--;
		Dq[++Tl]=make_pair(mx,i);
		while(Hd<=Tl&&Dq[Hd].second>i+l-1) ++Hd;
		tmp[n-i-l+2]=max(tmp[n-i-l+2],Dq[Hd].first);
	}
	roff(i,l-1,1) {
		while(Hd<=Tl&&Dq[Hd].second>i) ++Hd;
		tmp[n-i+1]=max(tmp[n-i+1],Dq[Hd].first);
	}
	return ;
}

int main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	ffor(i,1,n) cin>>a[i],pre[i]=pre[i-1]+a[i];
	ffor(i,1,n) Pre[i]=Pre[i-1]+a[n-i+1];

	int t=log2(n);
	ffor(i,0,t) {
		int l=(1<<i),r=(1<<i+1);
		ffor(j,1,n) tmp[j]=-LONG_LONG_MAX;
		solve(l,r),Solve(l,r);
		ffor(j,1,n) res[i][i][j]=tmp[j];
	}
	roff(i,t,0) ffor(j,i+1,t) ffor(p,1,n) res[i][j][p]=max(res[i][j-1][p],res[i+1][j][p]);
	cin>>q;
	ffor(i,1,q) {
		int l,r;
		cin>>l>>r;
		ffor(j,1,n) tmp[j]=-LONG_LONG_MAX;
		if(r<=2*l) solve(l,r),Solve(l,r);
		else {
			int t1=1,t2=1;
			while(t1<l) t1+=t1;
			while(t2+t2<=r) t2+=t2;
			if(t1<t2) {
				int X=log2(t1),Y=log2(t2)-1;
				ffor(j,1,n) tmp[j]=res[X][Y][j];
			}
			solve(l,min(r,t1)),solve(max(l,t2),r),Solve(l,min(r,t1)),Solve(max(l,t2),r);
		}
		output();
	}
	return 0;
}
