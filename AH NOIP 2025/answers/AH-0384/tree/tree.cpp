#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
ll read(){
    char cc=getchar();
    int f=1,x=0;
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
        cc=getchar();
    }while(isdigit(cc));
    return f*x;
}
void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
const int N=8005;
int n,pre[N],s[N],hson[N],dfn[N],tot;
bool a[N];
vector<int>t[N];
void dfs1(int u){
    s[u]=1;
    for(int&v:t[u]){
        dfs1(v);
        s[u]+=s[v];
        if(s[v]>s[hson[u]]){
            a[hson[u]]=0;
            a[v]=1;
            hson[u]=v;
        }
    }
}
void dfs2(int u){
    if(t[u].size()){
        dfs2(hson[u]);
        if(t[u].size()>1){
            for(int&v:t[u]){
                if(v^hson[u]){
                    dfs2(v);
                }
            }
        }
    }
    dfn[u]=tot++;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int T=read();
    do{
        n=read();
        for(int i=2;i<=n;++i){
            pre[i]=read();
        }
        dfs1(1);
        dfs2(1);
        int ans=0;
        for(int i=1;i<=n;++i){
            if(a[i]){
                ans+=dfn[i]+1;
            }
        }
        print(ans);
        putchar('\n');
    }while(--T);
    return 0;
}
