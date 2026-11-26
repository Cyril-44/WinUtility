#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define local
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N = 100005;
ll Y[N];
ll X[N];
struct S{
    ll id,val,c;
    bool x;
    bool operator<(const S &s)const{
        double x1 = (double)val/(double)c;
        double x2 =  (double)s.val/(double)s.c;
        if(x1 == x2)return c > s.c;
        return x1 > x2;
    }
};
void solve(){
    int n;ll m;
    cin>>n>>m;
    priority_queue<S>pq;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        Y[i] = y;
        X[i] = x;
        pq.push({i,x,1,1});
        pq.push({i,x+y,2,0});
    }
    ll ans = 0;
    while(!pq.empty()){
        S s = pq.top();pq.pop();
        if(m<s.val)continue;
        if(s.x){
            ans +=1;
            pq.push({s.id,Y[s.id],1,0});
            m-=s.val;
        }else if(s.c == 1){
            ans += 1;
            pq.push({s.id,X[s.id],1,1});
            m-=s.val;
        }else{
            ans += 2*(m/s.val);
            m = m % s.val;
        }
    }
    cout<<ans<<endl;
}

int main(){
    #ifdef local
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0*114514*0;
}