#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mo=998244353;
ll c,t,n,m,a[50010],ans;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,cmp);
        ll sum=0;
        if(a[1]>a[2]+a[3]){
            for(ll i=2;i<=n;i++){
                if(a[i]*2>a[1]) sum++;
                else break;
            }
        }
        ans=((ll)pow(2,n)-((((ll)pow(2,sum)-1)%mo)*(ll)pow(2,n-sum-1)))%mo;
        cout<<ans;
    }
    return 0;
}
