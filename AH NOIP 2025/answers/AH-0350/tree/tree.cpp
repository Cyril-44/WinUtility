#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0;bool f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
int n,m;
const int dd=40+5;
struct node{
    vector<int>son;
    int v,dep,fa;
};vector<node>t(dd);int ans;
bitset<dd>lj;
int MEX(bitset<dd>&vis){
    for(int i=0;i<=n;i++)
        if(!vis[i])
            return i;
    return n+1;
}
int solve(int x){
    int ans=0;bitset<dd>vis=0;
    for(auto it:t[x].son){
        ans+=solve(it);vis|=lj;
    }vis[t[x].v]=1;
    lj=vis;
    return ans+MEX(vis);
}
void dfs(int now){
    if(now>n){
        ans=max(ans,solve(1));
        return;
    }
    for(int i=0;i<=n;i++){
        t[now].v=i;
        dfs(now+1);
    }
}
node empt;
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T=read();
    while(T--){
        n=read(),m=read();ans=0;
        for(int i=0;i<dd;i++)
            t[i]=empt;
        for(int i=2;i<=n;i++){
            t[i].fa=read();
            t[t[i].fa].son.push_back(i);
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
