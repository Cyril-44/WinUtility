#include<bits/stdc++.h>
using namespace std;
struct s{
    long long x,y;
    bool c;
};
vector<s> g;
set<pair<long long,long long>> s;
long long dp[100010];
int n;
long long m,ans;
void dfs(long long cnt,long long he){
    for(int i=0;i<g.size();i++){
        if(g[i].c==0){
            if(he+g[i].x<=m){
                g[i].c=1;
                dfs(cnt+1,he+g[i].x);
                g[i].c=0;
            }
        }else{
            if(he+g[i].y<=m){
                g[i].c=0;
                dfs(cnt+1,he+g[i].y);
                g[i].c=1;
            }
        }
    }
    ans=max(ans,cnt);
    return;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a,b;
        cin>>a>>b;
        if(!s.count(make_pair(a,b))){
            s.insert(make_pair(a,b));
            g.push_back({a,b,0});
        }
    }
    if(m<=20){
        dfs(0,0);
        cout<<ans;
    }else{
        for(int i=0;i<g.size();i++){
            for(int j=g[i].x;j<=m;j++){
                dp[j]=max(dp[j],dp[j-g[i].x]+1);
            }
        }
        cout<<dp[m];
    }
    return 0;
}
