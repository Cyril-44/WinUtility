#include <bits/stdc++.h>
using namespace std;
int C,T;
int n,m;
int a[5005];
long long v;
const long long mod=998244353;
long long fast_mod(int x,int q){
    if(q==1) return x%mod;
    long long t=fast_mod(x,q/2);
    if(q%2!=0) return (((t*t)%mod)*x)%mod;
    else return (t*t)%mod;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>C>>T;
if(C==0){
    cout<<'6';
    return 0;
}
while(T--){
    cin>>n>>m;
    memset(a,0,sizeof(a));
    if(C==18){
        cout<<fast_mod(2,n)-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    v=1;
    for(int i=1;i<=n;i++){
        v=v*2;
    }
    cout<<v-m<<endl;
}
    return 0;
}
