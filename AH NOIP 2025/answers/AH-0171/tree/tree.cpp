#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int MAXN=8010;

int t,n,m,ans;
int rd[MAXN],cnt[MAXN];
vector<int> G[MAXN];

int coun(int u){
    int now=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        now=now+coun(v);
    }
    cnt[u]=now;
    return now+1;
}

void dfs(int u,int zg){
    int maxn=-1,idx=-1,sum=cnt[u];
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        int now=cnt[v];
        if(now>maxn){
            maxn=now;
            idx=v;
        }
    }
    ans=ans+sum+1;
    //cout<<u<<" "<<sum+1<<endl;
    if(idx!=-1) dfs(idx,1);
    /*for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(idx==v) continue;
        ans=ans+lea[v];
    }*/
    return ;
}

int dfs2(int u,int x){
    int cnt=0;
    if(rd[u]==0){
        if(x==0) ans++;
        //cout<<u<<" "<<x<<endl;
        return x;
    }
    int maxn=-1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(rd[v]==0){
            cnt++;
            continue;
        }
        maxn=max(maxn,dfs2(v,0));
    }
    int now=maxn;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(rd[v]==0){
            now=now+1;
            dfs2(v,now);
        }
    }
    now++;
    ans=ans+now+1;
    //cout<<u<<" "<<maxn<<endl;
    return now;
}

void solve(){
    cin>>n>>m;
    ans=0;
    for(int i=1;i<=n;i++) rd[i]=0,G[i].clear();
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        G[x].push_back(i);
        rd[x]++;
    }
    coun(1);
    dfs(1,1);
    int ans2=ans;
    ans=0;
    int xxx=dfs2(1,0);
    cout<<max(ans,ans2)<<endl;
    return ;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    cin>>t;
    while(t--){
        solve();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
