#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=5e4+5,mod=998244353;
int n,m;
ll a[N],pw[N],jc[N],invjc[N];
ll ksm(ll k,int x){
    ll rt=1;
    while (x){
        if (x&1) rt=rt*k%mod;
        k=k*k%mod,x>>=1;
    }
    return rt;
}
ll C(int a,int b){
    if (b<0||b>a) return 0;
    return jc[a]*invjc[b]%mod*invjc[a-b]%mod;
}
void add(ll &a,ll b){
    if ((a+=b)>=mod) a-=mod;
}

void solve(){
    cin>>n>>m;
    ll ans=pw[n];
    up(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    up(i,1,n){
        int pos=0;
        down(j,i-1,1){
            if (a[j]*2<=a[i]) break;
            if (a[j]==a[i]) continue;
            ll c=C(n-j-1,m-(n-i)-2);
            if (c==0) continue;
            while (pos<i&&a[pos]<a[i]-a[j]) pos++;
//            int pos=lower_bound(a+1,a+n+1,a[i]-a[j])-a-1;
            add(ans,mod-c*pw[pos-1]%mod);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    jc[0]=invjc[0]=pw[0]=1;
    up(i,1,5000){
        pw[i]=pw[i-1]*2%mod;
        jc[i]=jc[i-1]*i%mod;
        invjc[i]=ksm(jc[i],mod-2);
    }
    int c,t;cin>>c>>t;
    while (t--) solve();
    return 0;
}
