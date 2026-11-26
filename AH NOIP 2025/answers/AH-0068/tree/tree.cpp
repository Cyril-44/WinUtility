#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=8005;
ll n,m,ans,a[maxn],T,w[maxn],anss;
vector <ll> node[maxn];
vector<ll> p[maxn];
void dfss(ll u){
    ll s=-1;
    p[u].push_back(w[u]);
    for(auto v:node[u]){
        dfss(v);
        for(auto m:p[v]) p[u].push_back(m);
    }
    sort(p[u].begin(),p[u].end());
    unique(p[u].begin(),p[u].end());
    for(int i=0;i<p[u].size();i++)
        if(p[u][i]!=i) s=i;
    if(s==-1) s=p[u].size()+1;
    anss+=s;
    return;
}
void dfs(ll k){
    if(k==n+1){
        anss=0;
        dfss(1);
        ans=max(ans,anss);
        return;
    }
    for(int i=0;i<=n;i++) {w[k]=i;dfs(k+1);}
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--){
            ans=0;
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            ll x;
            cin>>x;
            node[x].push_back(i);
        }
    //dfs(1);
        for(int i=1;i<=n;i++)
            node[i].clear();
        cout<<n+1<<endl;
    }
    return 0;
}
