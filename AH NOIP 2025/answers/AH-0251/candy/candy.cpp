#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,a[100005][5],k[100005];
void dfs(int ans,int t){
    if(ans>m) return;
    maxn=max(maxn,t);
    for(int i=1;i<=n;i++){
        k[i]=(k[i]+1)%2;
        dfs(ans+a[i][k[i]],t+1);
        k[i]=(k[i]+1)%2;
    }
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    memset(k,1,sizeof(k));
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    dfs(0,0);
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
