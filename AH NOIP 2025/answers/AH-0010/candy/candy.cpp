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

const int N=2e5+5;
int n; ll m;
ll v1[N],v2[N];

inline void init () {
    in (n),in (m);
    for (int i=1,x,y;i<=n;++i) {
        in (x),in (y);
        v1[i]=x,v2[i]=x+y;
    }
}

inline void work () {
    sort(v1+1,v1+n+1);
    sort(v2+1,v2+n+1);
    for (int i=1;i<=n;++i) v1[i]+=v1[i-1];
    ll ans=0;
    for (int i=0;i<=n;++i) {
        if (m>=v1[i]) ans=max(ans,i+(m-v1[i])/v2[1]*2);
    }
    printf ("%lld\n",ans);
}


int main() {
    freopen ("candy.in","r",stdin);
    freopen ("candy.out","w",stdout);
    int tes; tes=1; while (tes--) {
        init();
        work();
    }
    return 0;
}