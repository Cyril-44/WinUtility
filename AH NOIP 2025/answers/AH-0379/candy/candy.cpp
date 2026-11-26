#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000],b[200000];
long long u[500000],v[500000];
long long cnt=0;
long long ans=0,dq=0;
int  main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        u[i]=a[i];
        v[i]=a[i]+b[i];
    }
    sort(v+1,v+1+n);
    sort(u+1,u+1+n);
    ans=(m-dq)/v[1]*2;
    for(long long i=1;i<=n;i++){
        dq=dq+u[i];
        ans=max(ans,i+(m-dq)/v[1]*2);
    }
    cout<<ans;
    return 0;
}
//!noip@Nov29,2025:dream
