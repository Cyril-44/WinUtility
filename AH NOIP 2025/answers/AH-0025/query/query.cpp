#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[50005],cnt[50005],ans[50005];
unsigned long long anss;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cnt[i]=cnt[i-1]+a[i];
    }
    cin>>q;
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        anss=0;
        for(int i=1;i<=n;i++){
            ans[i]=-1e18;
            for(int j=l;j<=r;j++){
                for(int k=max(1,i-j+1);k<=i&&k+j-1<=n;k++){
                    ans[i]=max(ans[i],cnt[k+j-1]-cnt[k-1]);
                }
            }
            anss^=1llu*i*ans[i];
        }
        printf("%llu\n",anss);
    }
    return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
