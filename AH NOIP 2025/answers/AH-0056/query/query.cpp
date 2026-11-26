#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
ll a[50005];
ll sum[50005];
void out(__int128 x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
struct  tree{
	ll l,r,mx;
}tr[300005];
void update(ll id){
    tr[id].mx=max(tr[id*2].mx,tr[id*2+1].mx);
}
void build(ll id,ll l,ll r){
	if(l==r){
		tr[id].l=tr[id].r=l;
		tr[id].mx=sum[l];
		return;
	}
	tr[id].l=l,tr[id].r=r;
	ll mid=tr[id].l+tr[id].r>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	update(id);
}
ll mx(ll id,ll l,ll r){
    if(tr[id].l>=l&&tr[id].r<=r){
        return tr[id].mx;
    }
    ll res=-1e18;
    ll mid=tr[id].l+tr[id].r>>1;
    if(l<=mid)res=max(res,mx(id*2,l,r));
    if(r>=mid+1)res=max(res,mx(id*2+1,l,r));
    return res;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    build(1,1,n);
    scanf("%lld",&q);
    __int128 mod=1;
    for(ll i=1;i<=64;i++)mod*=2;
    while(q--){
        ll L,R;
        __int128 ans=0;
        scanf("%lld%lld",&L,&R);
        for(ll i=1;i<=n;i++){
            __int128 res=-1e18;
            for(ll l=max(1ll,i-R+1);l<=i;l++){
				ll t=mx(1,max(l+L-1,i),min(l+R-1,n))-sum[l-1];
                    if(res<t)res=t;
                   // cout<<i<<" "<<l<<" "<<r<<endl;
            
            }
			ans=ans xor ((i*res)%mod);
        }
		out((ans+mod)%mod);
		puts("");
    }
}
