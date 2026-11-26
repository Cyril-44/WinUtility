#include<bits/stdc++.h>
using namespace std;
long long T,n,m,a[5010],c,pw[5010];
constexpr unsigned long long p=998244353;
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    pw[0]=1;
    for(int i=1;i<=5000;i++)pw[i]=pw[i-1]*2%p;
    while(T--){
        long long sum=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(m<=1){cout<<0<<endl;continue;}
        sort(a+1,a+1+n,[](long long a,long long b){
            return a>b;
        });
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<n;j++){
                int x=-(upper_bound(a+j+1,a+n+1,a[i]/2-a[j])-lower_bound(a+j+1,a+n+1,a[i]-a[j]));
                cout<<x<<endl;
                if(x>0)sum+=pw[n-3]*x;
                sum%=p;
            }
        }
        cout<<pw[n]-sum<<endl;
    }
    return 0;
}
