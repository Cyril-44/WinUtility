#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 20005
#define mod 998244353
using namespace std;
int C,T,n;
typedef long long ll;
ll a[MAXN],w[MAXN],m;
ll qpow(int x,int k){
    if(k==0) return 1;
    ll ret=qpow(x,k/2);
    if(ret%2==0) return ret*ret%mod;
    else return ret*ret%mod*x%mod;
}
bool same(){
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1])
            return false;
    return true;
}
struct node{
    ll x,w,val;
}s[MAXN];
bool cmp(node a,node b){
    if(a.val!=b.val)
        return a.val>b.val;
    return a.x>b.x;
}
ll dp[MAXN],ans;
void ANS(){
    for(int i=1;i<=n;i++){
        s[i]=(node){a[i],w[i],a[i]*2/w[i]};
    }
    sort(s+1,s+n+1,cmp);
    ll sum=0,cost=m;
    for(int i=1;i<=n;i++){
        if(cost>=s[i].w){
                //cout<<s[i].x<<" ";
            cost-=s[i].w;
            sum+=s[i].x;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j-w[i]]+a[i],dp[j]);
        }
    }
    if(sum==dp[m]) ans++;
    //for(int i=1;i<=n;i++) cout<<w[i]<<" ";
    //cout<<endl;
    //for(int i=1;i<=n;i++) cout<<s[i].x<<" ";
    //cout<<endl<<" "<<sum<<","<<dp[m]<<endl;
    ans%=mod;
    return ;
}
void dfs(int x){
    if(x>n){
        //cout<<1<<endl;
        ANS();
        return ;
    }
    w[x]=1;
    dfs(x+1);
    w[x]=2;
    dfs(x+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>C>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        if(same()){
            cout<<qpow(2,n)<<endl;
            continue;
        }
        if(m==2){
            if(a[n]>=a[n-1]*2){
                cout<<qpow(2,n)<<endl;
            continue;
            }
        }
        dfs(1);
        //if(ans==6){
            //    cout<<m<<endl;
            //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        //}
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 1
5 8
352072622 352072622 363458478 373198377 746396754
*/
