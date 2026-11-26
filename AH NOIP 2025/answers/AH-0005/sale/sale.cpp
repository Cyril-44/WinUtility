#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=5e3+5; const ll Md=998244353;
int n,m; int a[N];
ll com[N][N],pw[N];

void wk() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i];
    pw[0]=1; for(int i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%Md;
    sort(a+1,a+n+1); reverse(a+1,a+n+1);
    com[0][0]=1;
    for(int i=1;i<=n;++i) {
        com[0][i]=1; for(int j=1;j<=i;++j) com[j][i]=(com[j-1][i-1]+com[j][i-1])%Md;
    }
    ll ans=0;
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            if(a[i]==a[j] || a[i]>=a[j]*2) continue;
            ll o=ans;
            for(int k=0;k<i;++k) {
                int w=j+k-1-(m-1); if(w<0 || w>j-i-1) continue;
                ans=(ans+com[k][i-1]*com[w][j-i-1])%Md;
            }
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            ll o=ans;
            for(int p=1;p<=j;++p) {
                if(p==i || p==j || a[i]<=a[p]+a[j] || a[p]*2<=a[i]) continue;
                if(p<i) {
                    for(int k=0;k<p;++k) {
                        int sum=i-p+k+1;
                        if(sum==m) ans=(ans+com[k][p-1]*pw[n-j])%Md; 
                    }
                }
                else {
                    for(int k=0;k<i;++k) {
                        int w=k+p-m;
                        if(w<0 || w>p-i-1) continue;
                        ans=(ans+com[k][i-1]*com[w][p-i-1]*pw[n-j])%Md;
                    }
                }
            }
        }
    }
    cout << (pw[n]+Md-ans)%Md << "\n";
}

signed main() {
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);

    ios::sync_with_stdio(false);

    int c,t; cin >> c >> t; // t=1;

    for(;t--;) wk();

    return 0;
}