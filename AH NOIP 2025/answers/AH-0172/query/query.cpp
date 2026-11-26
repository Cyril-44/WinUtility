#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define local
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N = 50005;
struct S{
    ll ans,l,r;
};
unsigned ll Mod = 1;
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n+1),sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        vector<ll>ans(n+1,-1e18);
        
        for(int len = l;len <= r;len ++){
            deque<S>dq;
            deque<S>st;
            for(int x = 1,y = x+len-1;y<=n;x++,y++){
                ll sums = sum[y]-sum[x-1];
                dq.pb({sums,x,y});
            }
            dq.pb({(ll)-1e18,1,n+1});
            int tot = 0;
            st.pb(dq[0]);
            for(int i=1;i<=n;i++){
                while(dq[tot+1].l<=i && dq[tot+1].r >= i){
                    if(dq[tot+1].ans = -1e18)break;
                    tot++;
                    while(!st.empty() && st.back().ans < dq[tot].ans){
                        st.pop_back();
                    }
                    st.pb(dq[tot]);
                }
                while(!st.empty()&&st.front().r < i)st.pop_front();
                ans[i] = max(ans[i],st.front().ans);
            }
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        ll ans2 = 0;
            for(ll i=1;i<=n;i++){
                cout<<ans[i]<<" ";
                ll ans1 = (i*ans[i]);
                if(ans1 > 0){
                    ans2 ^= ans1;
                    ans2 %= Mod;
                }
                else{
                    ans1 += Mod;
                    ans1 += Mod;
                    ans2 ^= ans1;
                    ans2%=Mod;
                }
            }
            cout<<ans2<<endl;
    }
}

int main(){
    #ifdef local
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    #endif
    for(int i=1;i<=63;i++)Mod *= 2;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0*114514*0;
}