#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;

int n,m;
int c[N],x[N];

signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        int u,v;cin >> u >> v;
        c[i] = u + v,x[i] = u;

    }
    sort(c + 1,c + n + 1);sort(x + 1,x +n + 1);
    int sum = 0,ans = (m / c[1]) *2;
    for(int i = 1;i <= n;i ++){
            //if(x[i] > c[1] / 2) break;
        if(m >= x[i]) {
                m -= x[i],sum ++;
                ans = max(ans,sum + (m / c[1]) *2);
       }
    }
   // sum += (m / c[1]) *2;
    cout << ans;

    return 0;
}
