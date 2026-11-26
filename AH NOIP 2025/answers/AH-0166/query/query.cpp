#include<bits/stdc++.h>
using namespace std;
long long q,n,m,a[5010];
constexpr unsigned long long p=-3;
unsigned long long qpow(unsigned long long a,unsigned long long b){
    unsigned long long res=1;
    while(b){
        if(b&1)res*=a;
        a*=a;
        b/=2;
    }
    return res;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q;
    //cout<<qpow(-3,p)<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        unsigned long long ans=0;
        for(int i=1;i<=n;i++){
            int t=max(a[i],max(a[i]+a[i-1],a[i]+a[i+1]));
            unsigned long long tmp=abs(t);
            if(r==1)ans^=qpow(i*a[i],p);
            else if(r==2)ans^=qpow(tmp*i,p);
            else {
                t=max(t,int(a[i]+a[i-1]+a[i+1]));
                tmp=abs(t);
                ans^=qpow(tmp*i,p);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
