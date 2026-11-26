#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,m,ans,f[15][15],a[15];
vector<int>g[15];
void dp(int u){
    f[u][a[u]]=1;
    int sz=g[u].size();
    for(int i=0;i<sz;i++){
        int v=g[u][i];
        dp(v);
        for(int j=0;j<=n;j++)f[u][j]|=f[v][j];
    }
}
int check(){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n+1;j++){
            if(!f[i][j]){
                sum+=j;
                break;
            }
        }
    }
    return sum;
}
void dfs(int x){
    if(x==n+1){
        memset(f,0,sizeof(f));
        dp(1);
        ans=max(ans,check());
        return ;
    }
    for(int i=0;i<=n;i++){
        a[x]=i;
        dfs(x+1);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=2,u;i<=n;i++){
            scanf("%d",&u);
            g[u].push_back(i);
        }
        dfs(1);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
