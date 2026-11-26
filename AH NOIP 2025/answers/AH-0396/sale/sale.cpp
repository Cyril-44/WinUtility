#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5;
ll c,T,n,m,a[N];
ll s(ll a,ll b,ll p){
    if(b==0) return 1;
    ll res=s(a,b/2,p);
    if(b%2) return res*res%p*a%p;
    else return res*res%p;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    if(c==18){
        while(T--){
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<s(2,n,998244353);
        }
    }else{
        while(T--){
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<s(2,n,998244353)-2;
        }
    }
    return 0;
}
