#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=1e5+5;
int n; ll m;
ll a[N],b[N];

void wk() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i] >> b[i];
    ll mn=1e18; for(int i=1;i<=n;++i) mn=min(mn,a[i]+b[i]);
    sort(a+1,a+n+1); ll ans=m/mn*2;
    for(int i=1;i<=n;++i) {
        m=m-a[i]; if(m<0) break;
        ans=max(ans,m/mn*2+i);
    }
    cout << ans << "\n";
}

signed main() {
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    ios::sync_with_stdio(false);

    wk();

    return 0;
}