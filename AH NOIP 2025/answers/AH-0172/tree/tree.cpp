#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define local
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
int val[8005];
struct Node{
    map<int,int>m;
    int x;
}t[8005];
vector<int>son[8005];
ll ans = 0;
void check(int x,int n){
    t[x].m.clear();
    t[x].m[val[x]]++;
    for(auto i:son[x]){
        check(i,n);
        for(auto j:t[i].m){
            t[x].m[j.fi] += j.se;
        }
    }
    for(int i=0;i<n;i++){
        if(t[x].m[i] == 0){
            ans += i;
            return ;
        }        
    }
}
ll ans2 = 0;
void dfs(int x,int n){
    if(x == n+1){
        bool flag =0;
        for(int i=1;i<=n;i++){
            if(val[i] == 0){
                flag = 1;
                break;
            }
        }
        if(!flag)return;
        ans = 0;
        check(1,n);
        ans2 = max(ans,ans2);
        return;
    }
    for(int i=0;i<n;i++){
        val[x] = i;
        dfs(x+1,n);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>fa(n+1);
    for(int i=1;i<=n;i++){
        son[i].clear();
    }
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        son[fa[i]].pb(i);
    }
    dfs(1,n);
    cout<<ans2<<endl;
    ans2 = 0;
}

int main(){
    #ifdef local
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0*114514*0;
}