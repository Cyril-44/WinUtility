#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,s[50005],pre[50005];
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
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();
    for(ll i=1;i<=n;i++){
        s[i]=read();
        pre[i]=pre[i-1]+s[i];
    }
    q=read();
    while(q--){
        ll x=read(),ans=0;
        x=read();
        for(ll i=1;i<=n;i++){
            ll k=0;
            for(ll j=max(1ll,i-x+1);j+x-1<=n;j++){
                k=max(k,pre[j+x-1]-pre[j-1]);
            }
            ans^=(i*k);
        }
        cout<<ans<<'\n';
    }
    return 0;
}