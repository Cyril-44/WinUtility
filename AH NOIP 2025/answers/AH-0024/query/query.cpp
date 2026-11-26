#include<bits/stdc++.h>
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
const int N=5e4+5;
const ll inf=1e14;
int n,q;
ll a[N],pre[N];
int ql[N],qr[N];
ll ans[N];
ll st[17][N],lg[N];
void build(int _k,int _n){
	lg[0]=-1;
	for(int i=1;i<=_n;i++)lg[i]=lg[i/2]+1;
	for(int j=1;j<_k;j++)for(int i=1;(i+(1<<j)-1)<=_n;i++)
		st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
}
inline ll query(int l,int r){
	int k=lg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
int get(int u,int l,int r){
	ll res=-inf;
	for(int i=min(u,n-l+1);i;i--){
		int ql_=max(u,i+l-1),qr_=min(n,i+r-1);
		if(qr_<u)break;
		chkmax(res,(query(ql_,qr_)-pre[i-1]));
//		debug((query(ql_,qr_)-pre[i-1]));
	}
	return res;
}
ull answer(){
	ull res=0;
	for(int i=1;i<=n;i++)res^=(ull)i*ans[i];
	return res;
}
int que[N],hh,tt;
ll now[N];
int Sub1(){
	for(int i=1;i<=q;i++){
		int nl=ql[i];
		for(int i=1;i+nl-1<=n;i++)now[i]=pre[i+nl-1]-pre[i-1];
		hh=1,tt=0;
		for(int i=1;i<=n;i++){
			if(i+nl-1<=n){
				while((hh<=tt) && now[que[tt]]<now[i])tt--;
				que[++tt]=i;
			}
			while(que[hh]+nl-1<i)hh++;
			ans[i]=now[que[hh]];
		}
		cout<<answer()<<endl;
	}
	return 0;
}
ll mem[N][33];
ull ret[N];
db str;
int Sub2(){
	for(int nl=1;nl<=32;nl++){
		for(int i=1;i+nl-1<=n;i++)
			now[i]=pre[i+nl-1]-pre[i-1];
		hh=1,tt=0;
		for(int i=1;i<=n;i++){
			if(i+nl-1<=n){
				while((hh<=tt) && now[que[tt]]<now[i])tt--;
				que[++tt]=i;
			}
			while(que[hh]+nl-1<i)hh++;
			mem[i][nl]=now[que[hh]];
//			debug(i);
//			debug(mem[i][nl]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=32;j++)st[0][j]=mem[i][j];
		build(6,32);
		for(int j=1;j<=q;j++){
			ret[j]^=(ull)i*query(ql[j],qr[j]);
		}
	}
	for(int i=1;i<=q;i++)cout<<ret[i]<<'\n';
	return 0;
}
int Sub3(){
	for(int i=1;i<=n;i++)st[0][i]=pre[i];
	build(17,n);
	for(int i=1;i<=q;i++){
		int nl=ql[i],nr=qr[i];
		for(int j=1;j<=n;j++)ans[j]=get(j,nl,nr);
		cout<<answer()<<endl;
	}
	return 0;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	str=clock();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	cin>>q;
	for(int i=1;i<=q;i++)cin>>ql[i]>>qr[i];
	int ck1=1,ck2=1;
	for(int i=1;i<=q;i++)if(qr[i]>32)ck2=0;
	for(int i=1;i<=q;i++)if(qr[i]!=ql[i])ck1=0;
	if(ck1)return Sub1();
	if(ck2)return Sub2();
	return Sub3();
}
/*
code:
!noip@Nov29,2025:dream
4
2 4 -5 1
3
1 2
3 4
1 4
*/
