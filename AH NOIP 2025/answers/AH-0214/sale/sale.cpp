#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int m,n,a[50001];
ll ans=1;
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans%=mod;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<ans<<<<endl;
    }
    return 0;
}



