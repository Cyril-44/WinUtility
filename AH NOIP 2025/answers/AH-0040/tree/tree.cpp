#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int>g[9000];
int sz[9000],son[9000],f[5000][5000],F[9000];
void dfs(int x,int fa){
    sz[x]=1;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        if(v==fa)continue;
        dfs(v,x);
        sz[x]=sz[x]+sz[v];
        if(sz[son[x]]<sz[v])son[x]=v;
    }
}
void dfs2(int x){
   // cerr<<x<<endl;
    if(son[x])dfs2(son[x]);
    f[x][0]=-0x3f3f3f3f;
    for(int i=1;i<5000;i++){
        f[x][i]=f[son[x]][i-1];
    }
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==son[x])continue;
        dfs2(g[x][i]);
        int v=g[x][i];
        for(int j=4999;j>=0;j--){
            f[x][j]=max(f[x][j],f[x][j]+F[v]);
            if(j-sz[v]>=0)f[x][j]=max(f[x][j],f[x][j-sz[v]]);
        }
    }
    F[x]=-0x3f3f3f3f;
    for(int i=0;i<5000;i++){
        f[x][i]+=i;
        F[x]=max(F[x],f[x][i]);
    }
}
void solve(){

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].clear(),son[i]=0;;
    for(int i=2;i<=n;i++){
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    for(int i=1;i<5000;i++)f[0][i]=-0x3f3f3f3f;
    dfs(1,0);
    dfs2(1);
    cout<<F[1]<<endl;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
