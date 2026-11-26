#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[50005];
__int128 mod=ULLONG_MAX+1;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            int sum=0,Max=0,d[50005];
            for(int i=1;i<=l;i++)
                sum+=a[i];
            for(int i=1;i<=n-l;i++){
                Max=max(sum,Max);
                d[i]=Max;
                sum+=a[i+l],sum-=a[i];
            }
        }
    }
    return 0;
}
