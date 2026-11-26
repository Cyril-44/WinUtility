#include<bits/stdc++.h>
using namespace std;
int dp[2100][11000],ans;
long long m,n;
int c[1100][3];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    if(n>1000){
        int minn=-1,t;
        for(int q=1;q<=2*n;q++){
            cin>>t;
            if(minn==-1)minn=t;
            else minn=min(minn,t);
        }
        cout<<m/minn;
        return 0;
    }
    for(int q=1;q<=n;q++){
        cin>>c[q][1]>>c[q][2];
        c[q][2]+=c[q][1];
    }
    for(int q=1;q<=n;q++){
        for(int w=1;w<=m;w++){
            dp[q][w]=dp[q-1][w];
            if(w>=c[q][1])dp[q][w]=max(dp[q][w],dp[q-1][w-c[q][1]]+1);
        }
    }
    for(int q=n+1;q<=2*n;q++){
        for(int w=1;w<=m;w++){
            dp[q][w]=dp[q-1][w];
            if(w>=c[q-n][2])dp[q][w]=max(dp[q][w],dp[q][w-c[q-n][2]]+2);
        }
    }
    cout<<dp[2*n][m];
    return 0;
}
