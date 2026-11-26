#include<bits/stdc++.h>
using namespace std;
int dp[2][10005],n,m;
struct node{
    int x,y;
}a[100005];
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int f;
    f = 1;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        if(a[i].x!=a[i].y){
            f = 0;
        }
    }
    if(f){
        int minn;
        minn = 1e9;
        for(int i = 1;i<=n;i++){
            minn = min(minn,a[i].x);
        }
        cout<<m/minn<<"\n";
        return 0;
    }
    for(int i = 1;i<=n;i++){
        memset(dp[i%2],0,sizeof(dp[i%2]));
        int st,num;
        num = 0;
        st = 0;
        while(num<=m){
            st++;
            if(st%2){
                num+=a[i].x;
            }else{
                num+=a[i].y;
            }
        }
        if(st%2){
            num = num-a[i].x;
        }else{
            num = num-a[i].y;
        }
        for(int j = st-1;j;j--){
            for(int k = m;k>=num;k--){
                dp[i%2][k] = max(dp[i%2][k],dp[(i+1)%2][k-num]+j);
            }
            if(j%2){
                num = num-a[i].x;
            }else{
                num = num-a[i].y;
            }
        }
        for(int j = 1;j<=m;j++){
            dp[i%2][j] = max(dp[i%2][j],dp[(i+1)%2][j]);
        }
    }
    cout<<dp[n%2][m]<<"\n";
    return 0;
}
