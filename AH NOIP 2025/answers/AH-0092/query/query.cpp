#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pr pair<int,int>
using namespace std;
const ll N=1e5+10,inf=1e18;
ll T,n,a[N],sum[N];
unsigned ll ans;
void init()
{
    ans=0;
}
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    cin>>T;
    while(T--){
        init();
        ll L,R;
        cin>>L>>R;
        for(ll i=1;i<=n;i++){
            ll res=-inf;
            for(ll len=L;len<=R;len++){
                for(ll l=max((ll)1,(i-len+1));l<=i;l++){
                    ll r=min(n,l+len-1);
                    res=max(res,(sum[r]-sum[l-1]));
                }
            }
            ans^=(res*i);
            // cout<<i<<" "<<res<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}