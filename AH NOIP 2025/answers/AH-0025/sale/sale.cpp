#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int c,t,n,m;
ll f[5005][5005],a[5005],b[5005],C[5005][5005];//f[i][j]表示i位置剩j元的方案数
bool cmp(ll x,ll y){
    return x>y;
}
ll power(ll x,ll k){
    if(k<0) return 0;
    if(k==0) return 1;
    if(k==1) return x;
    if(k%2){
        ll y=power(x,k/2);
        return y*y%mod*x%mod;
    }
    else{
        ll y=power(x,k/2);
        return y*y%mod;
    }
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    C[0][0]=1;
    for(int i=1;i<=5000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int j=1;j<=m+2;j++){
            f[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m+2;j++){
                f[i][j]=0;
            }
            scanf("%lld",&a[i]);
            b[i]=-a[i];
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1);
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll cnt=1,cntt=0;
            int lst=i,nxt=i;
            for(int j=i-1;j>=1;j--){
                if(a[i]*2<=a[j]){
                    break;
                }
                lst=j;
            }
            for(int j=i+1;j<=n;j++){
                if(a[j]*2<=a[i]){
                    break;
                }
                nxt=j;
            }
            for(int j=i+1;j<=nxt;j++){
                cntt=1;
                int w=upper_bound(b+1,b+n+1,-a[i]+a[j])-b;
                int w2=upper_bound(b+1,b+n+1,-a[j]*2)-b;
                cntt=(cntt+power(2,n-w))%mod;
                for(int k=0;k<=i-w2;k++){
                    if(2+i-lst-k+lst-1>m) continue;
                    ans=(ans+cntt*C[i-w2][k]%mod*C[lst-1][m-(2+i-lst-k)-(lst-1)]%mod)%mod;
                }
            }
        }
        cout<<(power(2,n)-ans+mod)%mod<<endl;
    }
    return 0;
}
/*
3 15
1 7
2 3
3 1
*/
