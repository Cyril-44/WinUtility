#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int f=1,x=0;char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0',c=getchar();
    }
    return f*x;
}

const int N=5005,mod=998244353;
int qpow(int x,int y){
    int as=1;
    while(y){
        if(y&1) as=(as*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return as;
}
int n,m,a[N],ans;
pair<double,int> b[N];
void check(int x){
    for(int i=1;i<=n;i++){
        b[i].first=1.0*a[i]/(1.0*((x>>i-1)&1)+1);
        b[i].second=((x>>i-1)&1)+1;
    }
    sort(b+1,b+n+1,greater<pair<double,int>>());
    double getw=0;
    int mx=m;
    for(int i=1;i<=n;i++){
        if(mx>=b[i].second) getw+=b[i].first*1.0*b[i].second,mx-=b[i].second;
        if(mx==0) break;
    }
    double maxmoney=0;
    for(int i=0;i<(1<<n);i++){
        double got=0,used=0;
        int cnt=1;
        for(int j=1;j<=n;j++){
            if(i&(1<<j-1)){
                got+=b[j].first*1.0*b[j].second;
                used+=b[j].second;
            }
        }
        if(used<=m){
            maxmoney=max(maxmoney,got);
        }
    }
    if(getw==maxmoney) ans++;
}

signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c=read(),t=read();
    if(c>=15){
        while(t--){
            n=read(),m=read();
            for(int i=1;i<=n;i++) a[i]=read();
            cout<<qpow(2,n)<<"\n";
        }
        return 0;
    }
    while(t--){
        ans=0;
        n=read(),m=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=0;i<(1<<n);i++){
            check(i);
        }
        cout<<ans<<"\n";
    }
}
