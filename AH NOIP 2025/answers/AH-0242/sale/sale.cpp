#include<bits/stdc++.h>
#define ffor(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define inf 1e10
#define int unsigned long long
using namespace std;
const int N=5e3+5,mod=998244353;
int c,t,n,m,v[N];

int qpow(int x,int k){
    int ans=1;
    while(k){
        if(k&1) ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans;
}

void solve(){

}

void specA(){
    cin>>n>>m;
    ffor(i,1,n) cin>>v[i];
    cout<<qpow(2,n)<<endl;
}
void spec2(){

}

signed main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    //cout<<qpow(3,5)<<endl;
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    if(c==18){
        ffor(i,1,t) specA();return 0;
    }
    if(c==7 || c==8 || c==9 || c==14 || c==15){
        ffor(i,1,t) spec2();return 0;
    }
    ffor(i,1,t) solve();
    return 0;
}
