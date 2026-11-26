#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[5010];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        long long ji=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ji=ji*2%998244353;
        }
        cout<<ji<<endl;
    }
    return 0;
}
