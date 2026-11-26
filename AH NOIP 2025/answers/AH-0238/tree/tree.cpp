#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+int(c-'0');
        c=getchar();
    }
    return x*f;
}
void put_int(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    char c=(x%10)+'0';
    if(x>9){
        put_int(x/10);
    }
    putchar(c);
    return ;

}
void put_ll(long long x){

    if(x<0){
        putchar('-');
        x=-x;
    }
    char c=(x%10)+'0';
    if(x>9){
        put_ll(x/10);
    }
    putchar(c);
    return ;

}

struct S{
    int id;
    int child;

}x;
bool cmp(const S &x,const S &y){
    return x.child>y.child;

}
vector<S> G[8010];
int t,n,m;
long long ans=0;
int d[8010];
bool vis[8010];
int ch(int t){
    if(G[t].empty()){
        vis[t]=true;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<G[t].size();i++){
        S v=G[t][i];
        v.child=ch(v.id);
        cnt+=v.child+1;
    }
    sort(G[t].begin(),G[t].end(),cmp);
    return cnt;
}

int dfs(int t){
    int ct=0;
    int maxn=0;
    for(int i=0;i<G[t].size();i++){
        S v=G[t][i];
        if(vis[v.id]){
            if(ct==0){
                ans++;
            }
            d[v.id]=ct;
            ct++;
            maxn=max(ct,maxn);
        }
        else{

            d[v.id]=dfs(v.id);
            ans+=d[v.id];
            maxn=max(d[v.id],maxn);
        }
    }
    return maxn+1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        m=read();
        ans=0;
        for(int i=1;i<=n;i++){
            d[i]=0;
            vis[i]=false;
            G[i].clear();
        }
        for(int i=2;i<=n;i++){
            int p;
            p=read();
            x.id=i;
            x.child=0;
            G[p].push_back(x);
        }
        int ch1=ch(1);
        d[1]=dfs(1);
        ans+=d[1];
        put_ll(ans);
        putchar('\n');
    }

    return 0;
}
