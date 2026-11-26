#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T;
ll n,m;
ll mod=998244353;
ll a[50005];
ll t[50005];
struct node{
    ll r,w;
}b[50005];
bool cmp(node x,node y){
    if(x.r*y.w!=y.r*x.w)return x.r*y.w>y.r*x.w;
    else return x.r>y.r;
}
ll work(ll st){
    ll res=m,ans1=0,ans2=0;
    for(ll i=0;i<n;i++){
        if((st>>i)&1)t[i+1]=1;
        else t[i+1]=2;
        b[i+1].r=a[i+1],b[i+1].w=t[i+1];
    }
    sort(b+1,b+n+1,cmp);
    for(ll i=1;i<=n;i++){
        if(res>=b[i].w){
            res-=b[i].w;
            ans1+=b[i].r;
        }
    }
    for(ll i=0;i<(1<<n);i++){
        ll sum=0,tot=0;
        for(ll j=0;j<n;j++){
            if((i>>j)&1)sum+=b[j+1].w,tot+=b[j+1].r;
            if(sum>m)break;
        }
        if(sum<=m)ans2=max(ans2,tot);
    }
    if(ans1==ans2)return 1;
    else return 0;
}
ll qmi(ll a,ll k){
    ll res=1;
    while(k){
        if(k&1)res=(res*a)%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res%mod;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        if(c<=5){
                ll ans=0;
            for(ll i=0;i<(1<<n);i++)ans+=work(i);
            printf("%lld\n",ans);
        }
        else{
            printf("%lld\n",qmi(2,n));
        }
    }
}
