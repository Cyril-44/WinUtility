#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long I6;
int c,T,m,n,a[10000],A[10000],fac[100000],ifac[100000],mod=998244353,f[5000][5000];
int qpow(int a,int b){
    int s=1;
    for(;b;b>>=1,a=(I6)a*a%mod)if(b&1)s=(I6)s*a%mod;
    return s;
}
int C(int n,int m){
    if(m>n||m<0)return 0;
    return (I6)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int largerthan(int x){
    int*tmp=upper_bound(a+1,a+1+n,x);
    return n-(tmp-a)+1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<(qpow(2,n))%mod<<endl;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    fac[0]=ifac[0]=1;
    for(int i=1;i<80000;i++){
        fac[i]=(I6)fac[i-1]*i%mod;
        ifac[i]=qpow(fac[i],mod-2);
    }
    while(T--)solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
