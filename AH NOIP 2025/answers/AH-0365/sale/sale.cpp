#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int T,group;
int n,m,a[5005];
pair<int,int> b[5005];
int qpow(int a,int b){
    if(b==0) return 1;
    int t=qpow(a,b/2);
    if(b%2==0) return t*t%mod;
    return t*t%mod*a%mod;
}
signed main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>group>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<qpow(2,n)<<'\n';
    }
    return 0;
}
