#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define fi first
#define se second
template <typename T>
inline void in (T &x) {
    char c; int f=1;
    do {c=getchar(); (c=='-')&&(f=-1);} while(c>'9' || c<'0');
    for(x=0;c>='0' && c<='9';c=getchar()) x=(x*10)+(c^48);
    x*=f;
}

const int N=5005,mod=998244353;
inline int quip(int a,int b){int res=1; for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod; return res;}
inline void add(int &x,int y){x+=y; (x>=mod)&&(x-=mod);}
int n,m;
int a[N];
int fc[N],ifc[N],pw[N];

inline void init () {
    in (n),in (m);
    for (int i=1;i<=n;++i) in (a[i]),a[i]<<=1;
    sort(a+1,a+n+1,[&](int x,int y){return x>y;});
}
inline int C(int p,int q){return (p<q||p<0||q<0)?0:1ll*fc[p]*ifc[q]%mod*ifc[p-q]%mod;}

pii b[N];
ll c1[N],c2[N]; int t1,t2;

inline void work () {
    ll mx,nw; int mm;
    int ans=0;
    for (int S=0;S<(1<<n);++S) {
        t1=t2=0;
        for (int i=1;i<=n;++i) 
            if ((S>>(i-1))&1) b[i]={a[i]/2,2},c2[++t2]=a[i];
            else b[i]={a[i],1},c1[++t1]=a[i];
        sort(b+1,b+n+1,[&](pii x,pii y){return x.fi!=y.fi?x.fi>y.fi:(x.fi*x.se>y.fi*y.se);});
        for (int i=1;i<=t1;++i) c1[i]+=c1[i-1];
        for (int i=1;i<=t2;++i) c2[i]+=c2[i-1];
        mx=0;
        for (int i=0;i<=t1 && i<=m;++i) mx=max(mx,c1[i]+c2[min(t2,(m-i)/2)]);
        nw=0; mm=m;
        for (int i=1;i<=n;++i) {
            if (mm>=b[i].se) {
                mm-=b[i].se,nw+=b[i].fi*b[i].se;
            }
        }
        if (nw==mx) ++ans;
    }
    printf ("%d\n",ans);
}

inline void work1 () {
    int ans=1;
    ll mx,nw; int mm;
    for (int pos=1;pos<=n;++pos) {
        t1=t2=0;
        for (int i=1;i<=n;++i) 
            if (i!=pos) b[i]={a[i]/2,2},c2[++t2]=a[i];
            else b[i]={a[i],1},c1[++t1]=a[i];
        sort(b+1,b+n+1,[&](pii x,pii y){return x.fi!=y.fi?x.fi>y.fi:(x.fi*x.se>y.fi*y.se);});
        for (int i=1;i<=t1;++i) c1[i]+=c1[i-1];
        for (int i=1;i<=t2;++i) c2[i]+=c2[i-1];
        mx=0;
        for (int i=0;i<=t1 && i<=m;++i) mx=max(mx,c1[i]+c2[min(t2,(m-i)/2)]);
        nw=0; mm=m;
        for (int i=1;i<=n;++i) {
            if (mm>=b[i].se) {
                mm-=b[i].se,nw+=b[i].fi*b[i].se;
            }
        }
        if (nw==mx) ++ans;
    }
    for (int x=2;x<=n;++x)add(ans,C(n,x));
    printf ("%d\n",ans);
}


int main() {
    freopen ("sale.in","r",stdin);
    freopen ("sale.out","w",stdout);
    fc[0]=1; for (int i=1;i<=5000;++i) fc[i]=1ll*fc[i-1]*i%mod;
    ifc[5000]=quip(fc[5000],mod-2); for (int i=4999;i>=0;--i) ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
    pw[0]=1; for (int i=1;i<=5000;++i) pw[i]=(pw[i-1]<<1)%mod;
    int tes,ID; in(ID),in(tes); while (tes--) {
        init();
        if (ID==18 || m==2*n-1) {printf("%d\n",pw[n]); continue;}
        if (ID>=1 && ID<=5) {work(); continue;}
        if (m==2*n-2) {work1(); continue;}
    }
    return 0;
}