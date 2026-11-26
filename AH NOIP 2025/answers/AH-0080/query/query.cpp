#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+25,p=998244353,K=3e4+25;
ll a[N],b[N],n;
pair<ll,ll> f[18][K];
void init(){
	ll w=log2(n)+1,i;
	for(i=1;i<=n;i++)f[0][i]=make_pair(a[i],i);
	for(ll j=1;j<=w;j++)
		for(ll i=1;i+(1ll<<j)-1<=n;i++)
			f[j][i]=max(f[j-1][i],f[j-1][i+(1ll<<(j-1))]);
}
inline pair<ll,ll> cal(ll le,ll ri){
	ll k=log2(ri-le+1);
	return max(f[k][le],f[k][ri-(1ll<<k)+1]);
}
inline ll ls(ll k){return k<<1;}
inline ll rs(ll k){return (k<<1)+1;}
ll ans[N],lazy[N];
void build(ll k,ll l,ll r){
	if(l==r){ans[k]=lazy[k]=-1e18;return;}
	ll mid=(l+r)>>1;
	build(ls(k),l,mid);build(rs(k),mid+1,r);
	ans[k]=max(ans[ls(k)],ans[rs(k)]);lazy[k]=-1e18;
}
void block(ll k,ll v){
	lazy[k]=max(lazy[k],v);
	ans[k]=max(ans[k],v);
}
void downlazy(ll k){
	block(ls(k),lazy[k]);
	block(rs(k),lazy[k]);
	lazy[k]=-1e18;
}
void update(ll nl,ll nr,ll k,ll l,ll r,ll v){
	if(nl<=l&&r<=nr){block(k,v);return;}
	downlazy(k);
	ll mid=(l+r)>>1;
	if(nl<=mid)update(nl,nr,ls(k),l,mid,v);
	if(nr>mid)update(nl,nr,rs(k),mid+1,r,v);
	ans[k]=max(ans[ls(k)],ans[rs(k)]);
}
ll query(ll nl,ll nr,ll k,ll l,ll r){
	if(nl<=l&&r<=nr)return ans[k];
	downlazy(k);
	ll mid=(l+r)>>1,num=-1e18;
	if(nl<=mid)num=max(query(nl,nr,ls(k),l,mid),num);
	if(nr>mid)num=max(query(nl,nr,rs(k),mid+1,r),num);
    return num;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll i,que,le,ri;
	cin>>n;
	for(i=1;i<=n;i++)cin>>b[i],a[i]=a[i-1]+b[i];
	//init();
	
	cin>>que;
	while(que--){
		cin>>le>>ri;
		build(1,1,n);
		//for(i=1;i<=n;i++)cout<<ans[i]<<' '<<lazy[i]<<'\n';
		for(i=1;i<=n;i++)
			for(ll l=i+le-1;l<=i+ri-1&&l<=n;l++)update(i,l,1,1,n,a[l]-a[i-1]);
		/*for(i=1;i<=n;i++){
			ll l=min(i+le-1,n),r=min(i+ri-1,n);
			pair<ll,ll> w=cal(l,r);
			update(i,w.second,1,1,n,w.first-a[i-1]);
		}*/
		unsigned long long k=0;
		for(i=1;i<=n;i++)k^=(i*query(i,i,1,1,n));
		cout<<k<<'\n';
	}
	return 0;
}
