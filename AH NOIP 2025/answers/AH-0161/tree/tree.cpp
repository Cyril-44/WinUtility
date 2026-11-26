#include<bits/stdc++.h>
#define N 8005
using namespace std;
int t,n,m,s[N],a[N],d[N],mx[N],p[N][15],top[N],mxdep[N],dep[N][801];
long long ans;
vector<int>g[N];
inline int get_fa(int k,int u){
    for(int i=14;i>=0;i--)
        if((1<<i)<=k){
            k-=(1<<i);
            u=p[u][i];
        }
    return u;
}
void dfs(int u){
    mxdep[u]=d[u];
    dep[u][d[u]]++;
    s[u]=1;
    for(int i=1;i<15;i++)
        p[u][i]=p[p[u][i-1]][i-1];
    for(int v:g[u]){
        d[v]=d[u]+1;
        p[v][0]=u;
        dfs(v);
        s[u]+=s[v];
        mxdep[u]=max(mxdep[u],mxdep[v]);
        for(int i=d[v];i<=mxdep[v];i++)
            dep[u][i]+=dep[v][i];
    }
}
bool check(int x,int u){
    if(x==0)
        return true;
    for(int i=mxdep[u];i>=d[u];i--)
        if(dep[u][i]!=dep[x][i])
            return dep[u][i]>dep[x][i];
    return false;
}
void build_top(int u){
    int mx=0,id=0;
    for(int v:g[u])
        if(mx<mxdep[v]||(mx==mxdep[v]&&check(id,v))){
            mx=mxdep[v];
            id=v;
        }
    for(int v:g[u]){
        if(v==id)
            top[id]=top[u];
        else
            top[v]=v;
        build_top(v);
    }
}
void solve(int u){
    mx[u]=-1;
    for(int v:g[u]){
        solve(v);
        mx[u]=max(mx[u],mx[v]);
    }
    //cout<<u<<":\n";
    int res=0,mxpar=0;
    for(int i=0;i<=d[u];i++){
        int par=get_fa(i,u),tmp=d[par]-d[top[par]]+1;
        if(res<tmp){
            res=tmp;
            mxpar=par;
        }
        mx[par]=max(mx[par],mx[u]);
        //cout<<par<<' '<<tmp<<' '<<mx[par]+1<<endl;
    }
    a[u]=mx[mxpar]+1;
    mx[u]=max(mx[u],a[u]);
 //   cout<<u<<' '<<mxpar<<' '<<a[u]<<' '<<d[mxpar]-d[top[mxpar]]+1<<endl;
    ans+=d[mxpar]-d[top[mxpar]]+1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=2,p;i<=n;i++){
            cin>>p;
            g[p].push_back(i);
        }
        memset(dep,0,sizeof(dep));
        memset(p,0,sizeof(p));
        dfs(1);
        top[1]=1;
        build_top(1);
        ans=0;
        solve(1);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
