#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
int f=1,x=0;
char a;
a=getchar();
while(a>'9' || a<'0'){
if(a=='-')f=-1;
a=getchar();
}
while(a<='9' && a>='0'){
x=(x<<1)+(x<<3)+a-'0';
a=getchar();
}
return x*f;
}
int t;
int n,m,ans=0;
vector < int > edge[8010];
int dep[8010],deg[8010];
void add(int u,int v){
edge[u].push_back(v);
dep[v]=dep[u]+1;
dep[0]=max(dep[0],dep[v]);
}
void find_deg(int u){
int v;
for(int i=0;i<edge[u].size();i++){
    v=edge[u][i];
    find_deg(v);
    deg[u]++;
    deg[u]+=deg[v];
}
return;
}
void dfs(int u,int num){
if(u==0){
//cout<<u<<"="<<num<<endl;
ans++;
return;
}
int v;
int flag=0;
num=0;
    for(int i=0;i<edge[u].size();i++){
        v=edge[u][i];
        if(deg[v]>num){
            num=deg[v];
            flag=v;
        }
    }
    ans+=deg[u]+1;
    dfs(flag,0);
}
signed main(){
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
t=read();
while(t--){
n=read();m=read();
memset(dep,0,sizeof(dep));
memset(deg,0,sizeof(deg));
ans=0;
int u;
for(int i=2;i<=n;i++){
u=read();
add(u,i);
}
for(int i=1;i<=n;i++){
    for(int j=0;j<edge[i].size();j++){
        int v;
        v=edge[i][j];
        deg[i]+=deg[v];
    }
}
find_deg(1);
dfs(1,0);
cout<<ans<<endl;
for(int i=1;i<=n;i++)edge[i].clear();
}

return 0;
}
