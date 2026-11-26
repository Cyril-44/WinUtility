#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x[100005],y[100005];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    ll minn=INT_MAX;
    for(ll i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        minn=min(minn,x[i]+y[i]);
    }
    ll k=m/minn;
    ll ans=0;
    sort(x+1,x+n+1);
    for(ll i=k;i>=1;i--){
        ll rest=m-(i*minn),nans=i*2;
        for(ll j=1;j<=n;j++){
            if(rest>=x[j]){
                rest-=x[j];
                nans++;
            }
            else{
                break;
            }
        }
        if(nans<ans){
            break;
        }
        ans=nans;
    }
    cout<<ans<<'\n';
    return 0;
}