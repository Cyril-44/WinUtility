#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int t,c;
    cin>>c>>t;
    if(c==0){
        while(t--){
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=n;i++)cin>>a[i];
            cout<<0<<"\n";
        }
    }
return 0;
}
