#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[50005],s[50005],f[200005][20];
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        f[i][0]=s[i];
    }
    for(int i=1;i<=16;i++){
        for(int j=1;j<=n;j++)
            f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=1;i<=n;i++){
            int mx=-1e18;
            for(int j=i;j<=i+r;j++){
                int L=j-r,R=j-l;
                if(L>=i) continue;
                R=min(R,i-1);
                if(L==0){
                    L=1;
                    mx=max(mx,s[j]);
                }
                int len=__lg(R-L+1);
                mx=max(mx,s[j]-min(f[L][len],f[R-(1<<len)+1][len]));
            }
            ans^=(i*mx);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
