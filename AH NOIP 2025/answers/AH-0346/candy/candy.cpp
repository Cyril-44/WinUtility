#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[100005],b[100005],minn=1e18,sum;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld%lld",a+i,b+i);
    for(int i=1;i<=n;i++){
        minn=min(minn,a[i]+b[i]);
    }
    sort(a+1,a+n+1);
    ans=m/minn*2;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum<=m){
            ans=max(ans,i+(m-sum)/minn*2);
        }
    }
    cout<<ans;
    return 0;
}
/*
5 30
7 23
21 1
1 17
2 30
10 8
*/
