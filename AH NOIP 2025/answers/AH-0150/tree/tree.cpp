#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 200005
using namespace std;
int T,n,m,fa[MAXN],in[MAXN];
int depth[MAXN],num[MAXN],w[MAXN];
int son[MAXN],size[MAXN];
vector<int> g[MAXN];
void dfs(int u,int fa,int d){
    depth[u]=d;

    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=fa){
            //if(w[v]!=-1) w[u]=max(w[u],w[v]+1);
            dfs(v,u,d+1);
            //cout<<v<<"->"<<u<<": "<<mx<<endl;
        }

    }
}
void dfs2(int u,int fa){

    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=fa){
            dfs2(v,u);
            w[u]=max(w[u],w[v]+1);
            //cout<<v<<"->"<<u<<": "<<w[v]+1<<endl;
        }

    }
}
int ans;
void query(int u,int p){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=p){
            //ans+=(w[u]+1);
            //cout<<u<<"->"<<v<<" :"<<w[u]<<endl;
            query(v,u);
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        memset(w,-1,sizeof(w));
        memset(num,0,sizeof(num));
        cin>>n>>m;
        for(int i=0;i<=n;i++) g[i].clear();
        for(int i=2;i<=n;i++){
            int u;
            cin>>u;
            g[i].push_back(u);
            g[u].push_back(i);
            in[u]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                int k=g[i][j];
                if(!in[k]&&w[k]==-1){
                    w[k]=num[i]++;
                }
            }
        }
        dfs(1,0,0);
        dfs2(1,0);
        //query(1,0);
        for(int i=1;i<=n;i++){
            if(in[i]) ans+=(w[i]+1);
            if(!in[i]&&w[i]==0) ans++;
        }
        //for(int i=1;i<=n;i++) cout<<w[i]<<" ";
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
