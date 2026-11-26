#include<bits/stdc++.h>
//#define int long long
using namespace std;
int read(){
    int f=1,x=0;char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0',c=getchar();
    }
    return f*x;
}

const int N=105;
int n,m,a[N],fa[N],ans;
vector<int> son[N];
bool have[N];

void dfs2(int x){
    have[a[x]]=1;
    for(int y:son[x])
        dfs2(y);
}
void check(){
    int anss=0;
    for(int i=1;i<=n;i++){
        memset(have,0,sizeof(have));
        dfs2(i);
        int cnt=0;
        while(have[cnt]) cnt++;
        anss+=cnt;
    }
    ans=max(anss,ans);
}

void dfs(int st){
    if(st>n){
        check();
        return;
    }
    for(int i=0;i<=n;i++){
        a[st]=i;
        dfs(st+1);
    }
}

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T=read();
    while(T--){
        n=read(),m=read();ans=0;
        for(int i=1;i<=n;i++) son[i].clear(),son[i].shrink_to_fit();
        for(int i=2;i<=n;i++) fa[i]=read(),son[fa[i]].push_back(i);
        dfs(1);
        cout<<ans<<endl;
    }
}