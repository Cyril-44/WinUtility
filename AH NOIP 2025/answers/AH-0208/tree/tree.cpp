#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
const int N=1e5+5,Mod=998244353;
int n,m,t,p[N],s[N];
bool vis[N];
vector<int> G[N];
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=1;
        if(G[u].size()==1&&G[u][0]==p[u]){
            s[u]=s[p[u]];
            s[p[u]]++;
        }
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(vis[v])continue;
            q.push(v);
        }
    }
}
void dfs(int u,int fa){
    if(G[u].size()==1&&G[u][0]==p[u]){
        return ;
    }
    int cur=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
        cur=max(cur,s[v]);
    }
    s[u]=max(cur+1,s[u]);
    return ;
}
int qiuhe(int u,int fa){
    if(G[u].size()==1&&G[u][0]==p[u]){
        if(s[u]==0)return 1;
        else return 0;
    }
    int sum=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        sum+=qiuhe(v,u);
    }
    return sum+s[u]+1;
}
//怎么依旧只能过第一个样例（悲伤）
//这个方法错误百出，不想了
//估计只能解决m=2的情况
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    t=read();
    while(t--){
        n=read();m=read();
        for(int i=1;i<=n;i++){
            G[i].clear();
            s[i]=0;
            vis[i]=0;
            p[i]=0;
        }
        for(int i=2;i<=n;i++){
            int u;
            u=read();
            G[u].push_back(i);
            G[i].push_back(u);
            p[i]=u;
        }
        bfs(1);
        dfs(1,0);
        /*for(int i=1;i<=n;i++){
            cout<<s[i]<<' ';
        }*/
        write(qiuhe(1,0));
        puts("");
    }
    return 0;
}
