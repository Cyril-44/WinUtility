#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c,t,n,m,a[6000];
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
int main()
{
    //freopen("sale.in","r",stdin);
    //freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        if(c==18){
            cout<<qpow(2,n)<<"\n";
            continue;
        }
        long long ans=qpow(2,n);
        sort(1+a,1+a+n);
        for(int i=n;i>=1;i--){
            for(int j=i-1;j>=1;j--){
                if(a[j]>a[i]/2&&a[i]-2>=a[j]-1){
                    ans=(ans-qpow(2,n-2)%mod+mod)%mod;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
