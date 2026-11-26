#include<bits/stdc++.h>
using namespace std;
const int N=8e3+5;
int t,n,m;
vector<int> g[N];
int f[N][2],w[N][2],sz[N];
void dfs(int u){
    sz[u]=1;
    int k=0;
    for(int v:g[u]){
        dfs(v);
        sz[u]+=sz[v];
        f[u][0]=max(f[u][0],f[v][0]);
        if(f[v][0]>f[v][1]){
            f[u][1]+=f[v][0];
            k=max(k,w[v][0]);
        }else if(f[v][1]>f[v][0]){
            f[u][1]+=f[v][1];
            k=max(k,w[v][1]);
        }else{
            f[u][1]+=f[v][0];
            k=max(k,max(w[v][0],w[v][1]));
        }
    }
    w[u][0]=sz[u]-1;
    f[u][0]+=sz[u];
    if(g[u].size()==0){
        w[u][1]=0;
        f[u][1]=1;
        return ;
    }
    w[u][1]=k+1;
    f[u][1]+=k+2;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(w,0,sizeof(w));
        memset(f,0,sizeof(f));
        memset(sz,0,sizeof(sz));
        for(int i=2,x;i<=n;i++){
            cin>>x;
            g[x].push_back(i);
        }
        dfs(1);
        cout<<max(f[1][0],f[1][1])<<"\n";
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
    }
    return 0;
}
