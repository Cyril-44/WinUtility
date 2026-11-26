#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=10005,mod=998244353;
ll c,t,n,m,a[maxn],ans,w[maxn],f[25][25];
struct node{
    ll a,w;
    friend bool operator < (node x,node y){
        if(fabs(1.0*x.a/x.w-1.0*y.a/y.w)<1e-6)
            return x.a>y.a;
        else
            return 1.0*x.a/x.w>1.0*y.a/y.w;
    }
}p[maxn];
ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
bool check(ll x){
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(j>=p[i].w)
                f[i][j]=max(f[i-1][j],f[i-1][j-p[i].w]+p[i].a);
            else f[i][j]=f[i-1][j];
    return f[n][m]==x;
}
void dfs(ll k){
    if(k==n+1){
        node pp[30];
        for(int i=1;i<=n;i++) pp[i]=p[i];
        sort(pp+1,pp+n+1);
        ll sum=0,ww=m;
        //for(int i=1;i<=n;i++)
        //    cout<<pp[i].a<<' '<<pp[i].w<<endl;
        //cout<<endl;
        for(int i=1;i<=n;i++)
            if(ww>=pp[i].w){
            ww-=pp[i].w;
            sum+=pp[i].a;
        }
        if(check(sum)) {ans++;
        //cout<<"!!!"<<endl;
        }
        return;
    }
    p[k].w=1;
    dfs(k+1);
    p[k].w=2;
    dfs(k+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    if(c==18){
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<qpow(2,n)<<endl;
        }
    return 0;
    }
    if(c<=5){
        while(t--){
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++)
                cin>>p[i].a;
            dfs(1);
            cout<<ans<<endl;
        }
        return 0;
    }
    if(c==7||c==8||c==9||c==14||c==15){
        while(t--){
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                cin>>p[i].a;
                p[i].w==1;
            }

            cout<<ans<<endl;
        }
        return 0;
    }
    return 0;
}

