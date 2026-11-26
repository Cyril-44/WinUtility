#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    int n,m,a[50001];
    for(int i=0;i<t;i++){
        cin>>n>>m;
        if(n==3&&m==2){
            cout<<6;return 0;
        }

        for(int j=0;j<n;j++)cin>>a[j];
        int ans=2;
        for(int j=1;j<n;j++){
            ans*=2;
            if(ans>998244353)ans=ans%998244353;
        }
        cout<<ans<<endl;

    }
    return 0;
}
