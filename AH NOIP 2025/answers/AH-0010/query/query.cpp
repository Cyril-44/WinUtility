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

const int N=5e4+5;
const ll oo=1e18;
int n,Q;
int a[N]; ll s[N];

inline void init () {
    in (n);
    for (int i=1;i<=n;++i) in (a[i]);
    for (int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    in (Q);
}

ll mx[3005][3005];
inline void work0 () {
    for (int i=1;i<=n;++i) {
        mx[i][i]=s[i];
        for (int j=i+1;j<=n;++j) mx[i][j]=max(mx[i][j-1],s[j]);
    }
    ll ans=0; ull res;
    for (int L,R;Q--;) {
        in (L),in (R);
        res=0;
        for (int i=1;i<=n;++i) {
            ans=-oo;
            for (int l=0,lt,rt;l<i;++l) {
                lt=max(i,l+L),rt=min(n,l+R);
                if (lt<=rt) ans=max(ans,mx[lt][rt]-s[l]);
            }
            if (ans<=-oo) ans=-1;
            res^=(((ull)ans)*i);
        }
        printf ("%llu\n",res);
    }
}

inline void work () {
    
}


int main() {
    freopen ("query.in","r",stdin);
    freopen ("query.out","w",stdout);
    init();
    if (n<=3000 && Q<=50) {work0(); return 0;}
    work();
    return 0;
}