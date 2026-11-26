#include<bits/stdc++.h>
using namespace std;
unsigned long long qpow(unsigned long long a,unsigned long long b){
    unsigned long long ret=1;
    while(b){
        if(b&1){
            ret*=a;
        }
        a*=a;
        b>>=1;
    }
    return ret;
}
int n,a,q;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    cin>>q;
    while(q--){
        cin>>a>>a;
        cout<<qpow(2,a)<<'\n';
    }
    return 0;
}
