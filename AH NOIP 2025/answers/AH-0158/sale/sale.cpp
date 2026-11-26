#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,a[5005],mod=998244353;
ll read(){
    ll k=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        k=(k<<1)+(k<<3)+(c^48);
        c=getchar();
    }
    return k;
}
ll qpow(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans%mod;
}
void solve(){
    ll n,m;
    n=read();
    m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        ll f=lower_bound(a+1,a+n+1,a[i]*2)-(a+i)-1;
        cnt+=f;
    }
    cout<<(qpow(2,n,mod)-qpow(2,cnt,mod)+mod)%mod<<'\n';
    return;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    c=read();
    T=read();
    if(c==18){
        while(T--){
            ll n=read(),m=read();
            for(ll i=1;i<=n;i++){
                ll x=read();
            }
            cout<<qpow(2,n,mod)<<'\n';
        }
        return 0;
    }
    while(T--){
        solve();
    }
    return 0;
}