#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define mk make_pair
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return a>b?a:b;}
const int N=5005,inf=1e9+7,mod=998244353;
int cid,T,n,m,a[N];
pr b[N];
ll P[N],fac[N],ifac[N];
ll ksm(ll a,int b){
    ll res=1;for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
    return res;
}
ll C(int n,int m){return n<m||n<0||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    in(cid),in(T);
    P[0]=1;for(int i=1;i<N;++i) P[i]=P[i-1]*2%mod;
    fac[0]=1;for(int i=1;i<N;++i) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=ksm(fac[N-1],mod-2);for(int i=N-1;i;i--) ifac[i-1]=ifac[i]*i%mod;
    while(T--){
        in(n),in(m);
        for(int i=1;i<=n;++i) in(a[i]);
        sort(a+1,a+1+n,[](int x,int y){return x>y;});
        a[n+1]=0;
        ll ans=P[n];
        for(int y=1;y<=n;++y){
            for(int x=y+1,z=n+1;x<=n;++x){
                if(a[x]*2<=a[y]||a[y]==a[x]) continue;
                while(a[z]<a[y]-a[x]) z--;
                if(z<=n) ans-=P[n-z]*C(x-2,m-y-1)%mod;
            }
        }
        ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}