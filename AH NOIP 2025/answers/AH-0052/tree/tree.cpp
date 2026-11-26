#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &xxx){
    xxx=0;
    bool fll=0;
    char ccc=getchar();
    while(ccc<'0'||ccc>'9'){
        if(ccc=='-')fll=1;
        ccc=getchar();
    }
    while(ccc>='0'&&ccc<='9'){
        xxx=xxx*10+ccc-'0';
        ccc=getchar();
    }
    if(fll)xxx=-xxx;
}
const int N=16;
int n,m;
int t;
vector<int>g[N];
int w[N];
int no[N];
int dfs2(int u,int fa){
    int anss=0;
    for(int v:g[u]){
        if(v==fa)continue;
        anss+=dfs2(v,u);
        no[u]|=no[v];
    }
    no[u]|=(1<<w[u]);
    for(int i=0;i<=n+1;i++){
        if(((no[u]>>i)&1)==0){
            anss+=i;
            return anss;
        }
    }
    return anss;
}
int ans=0;
void dfs1(int x){
    if(x==n+1){
        memset(no,0,sizeof no);
        ans=max(ans,dfs2(1,1));
        return;
    }
    for(int i=0;i<n;i++){
        w[x]=i;
        dfs1(x+1);
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=2;i<=n;i++){
            int x;
            read(x);
            g[x].push_back(i);
            g[i].push_back(x);
        }
        dfs1(1);
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
}