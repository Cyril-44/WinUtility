#include<bits/stdc++.h>
#define for1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define for2(i,a,b) for(int i=(a);(i)>=(b);(i)--)
#define pedl cout<<"\n";
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define of pop_front
#define ob pop_back
#define ls (p<<1)
#define rs (p<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
using namespace std;
template<typename T> void cmax(T &x,T y){if(x<y) x=y;}
template<typename T> void cmin(T &x,T y){if(x>y) x=y;}
typedef pair<int,int> P;
typedef long long LL;
typedef double db;
typedef long double ldb;
const int base = 13331;
const int N = 8005;
const int M = 1e5 + 5;
const int mod = 998244353;

LL n,m;
LL fa[N];
vector<int> g[N];
bitset<365> qwq[365][365];
LL f[365][365];
void dfs(int u){
    for(int v:g[u]) dfs(v);
    for1(j,0,m-1){
        qwq[u][j][j]=1;
        for(int v:g[u]){
            
        }
    }
}
void solve(){
    cin>>n>>m;
    for1(i,2,n){
        cin>>fa[i];
        g[fa[i]].pb(i);
    }
    dfs(1);
    // for1(i)
    return ;
}

signed main(){
//    freopen("tree.in","r",stdin);
//    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int Testcase=1;
cin>>Testcase;
while(Testcase--){
    solve();
}
    return 0;
}
