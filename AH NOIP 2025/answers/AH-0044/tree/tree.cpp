#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<vector>

#define LL long long

using namespace std;

const int N=8000+10;

int T;
int n,m;
int fa[N];
int dep[N],siz[N];
int f[N],push[N],Son[N];
int ans=0;

vector<int>G[N];

void DFS1(int u){

    dep[u]=dep[fa[u]]+1;
    if(G[u].empty()){
        ans++;
        siz[u]=1,push[u]=0,f[u]=1;
        return ;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        DFS1(v);
        siz[u]+=siz[v];
        push[u]=max(push[u],push[v]);
        f[u]+=f[v];
        if(siz[v]>siz[Son[u]])
            Son[u]=v;
    }
    push[u]++;
    f[u]+=push[u]+1;
    siz[u]++;
    return ;

}

void Solve(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        siz[i]=0,f[i]=0,push[i]=0,dep[i]=0,Son[i]=0;
        G[i].clear();
    }
    for(int i=2;i<=n;i++){
        scanf("%d",&fa[i]);
        G[fa[i]].push_back(i);
    }
    ans=0;
    DFS1(1);
    printf("%d\n",max(f[1],ans));
    return ;

}

int main(){

    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    scanf("%d",&T);
    while(T--)
        Solve();
    printf("\n");
    return 0;

    fclose(stdin);
    fclose(stdout);

}
