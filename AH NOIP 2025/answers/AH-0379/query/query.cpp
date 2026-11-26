#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50100];
long long c[50100];
long long st[50100][100];
long long o=0;
 long long MOD=(1<<64);
long long maxn(long long a,long long b){
      if(a>b)return a;
      return b;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
       cin>>a[i];
       st[i][0]=a[i];
    }
    long long q=log(n);
    for(long long i=1;i<=q;i++){
        for(long long j=1;j+(1<<i)-1<=n;j++)
        st[j][i]=maxn(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
    cin>>m;
    while(m--){
        long long l,r;
        cin>>l>>r;
        l--;
        for(long long i=1;i<=n;i++){
            long long ll=maxn(1,i-l);
            long long rr=min(i+l,n);
            long long len=log(rr-ll+1);
            //cout<<1;
            c[i]=maxn(st[ll][len],st[rr-(1<<len)+1][len]);
            if(c[i]<0)c[i]+=(1<<64);
        }
        o=0;
        for(long long i=1;i<=n;i++){
          // cout<<c[i]<<endl;
           o=o^((i*c[i]));
           c[i]=0;
           o%=MOD;
         }
         cout<<o<<endl;
    }
    return 0;
}
//!noip@Nov29,2025:dream
