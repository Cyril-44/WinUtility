#include<bits/stdc++.h>
using namespace std;
int T,n,m;
const int N=8e3+5;
vector<int> g[N];
int ans;
int high;
struct node{
    int id,fa,dep,siz;
};
node a[N];
int v[N];
void dfst(int u){
    a[u].siz=1;
    for(int to:g[u]){
        if(to==a[u].fa) continue;
        dfst(to);
        a[u].siz+=a[to].siz;
    }
}
bool cmp(node u,node v){ return u.dep==v.dep?u.siz>v.siz:u.dep>v.dep;}
int s[N],cnts;
void init(){
    cnts=0;
    high=1;
    memset(v,0,sizeof v);
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++) g[i].clear();
}
void dfss(int u,int *arr,int bg){
    for(int to:g[u]){
        if(to==a[u].fa) continue;
        dfss(to,arr,cnts);
    }
    arr[++cnts]=v[u];
    sort(arr+bg,arr+cnts+1);
    if(arr[bg]!=0) return ;
    else{
        for(int i=2;i<=n;i++)
        if(arr[i]!=arr[i-1]+1) {
            ans+=arr[i-1]+1;
            return ;
        }
        ans+=arr[cnts]+1;
    }
}
void dfsv(int x,int val){
    v[x]=val;
    if(x==n){
        dfss(1,s,1);
        return ;
    }
    for(int i=1;i<=n;i++) dfsv(x+1,i);
}
void solve(){
    init();
    cin>>n>>m;
    a[1].dep=0;
    for(int i=2;i<=n;i++) {
        cin>>a[i].fa;
        g[i].push_back(a[i].fa);
        g[a[i].fa].push_back(i);
        a[i].dep=a[a[i].fa].dep+1;
        high=max(high,a[i].dep);
    }
    dfst(1);
    dfsv(0,1);
    cout<<ans<<'\n';
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--) solve();
    return 0;
}
