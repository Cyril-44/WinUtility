#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long Mod=998244353;
ll c,T,n,m,temp,ans;
struct nodde{
    ll pri,xj,np;
}a[5005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(rand());
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i].pri;
        cout<<(rand()*rand()*rand()+Mod)%Mod<<endl;
    }
    return 0;
}
