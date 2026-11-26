#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[50010];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    while(q--){
        ll l,r,anss;
        cin>>l>>r;
        for(ll k=1;k<=n;k++){
            ll ans=0;
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    if(k>=i&&k<=j){
                        ll sum=0;
                        for(ll z=i;z<=j;z++) sum+=a[z];
                        ans=max(ans,sum);
                    }
                }
            }
            if(k==1) anss=(k*ans)%(ll)pow(2,64);
            else anss=anss xor (k*ans)%(ll)pow(2,64);
        }
        cout<<anss<<endl;
    }
    return 0;
}
