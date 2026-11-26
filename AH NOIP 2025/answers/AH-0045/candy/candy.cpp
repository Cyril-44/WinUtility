#include <bits/stdc++.h>
using namespace std;
#define int long long
#define len 101000
int n, m, a[len], b[len], mn=0x3f3f3f3f3f, ans, ts;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i], mn=min(mn, a[i]+b[i]);
    sort(a+1,a+n+1), ans=m/mn*2;
    for(int i=1;i<=n;i++) {
        ts+=a[i];
        if(ts>m) break;
        ans=max(ans, i+(m-ts)/mn*2);
    }
    cout<<ans;
    return 0;
}
