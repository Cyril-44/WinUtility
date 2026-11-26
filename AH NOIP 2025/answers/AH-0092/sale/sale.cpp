#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pr pair<int,int>
using namespace std;
const int N=1e6+10,mod=998244353;
ll T,c,n,m,a[N],b[N],w[N],f[N],cnt,ans;
pr num[N];
bool cmp(pr x,pr y)
{
    return x.fi>y.fi;
}
void dfs(int dep)
{
    if(dep>n){
        ll tot=0,res=0,maxx=0;
        for(int i=1;i<=n;i++) num[i].fi=b[i],num[i].se=w[i];
        sort(num+1,num+n+1,cmp);
        // for(int i=1;i<=n;i++) cout<<w[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<=n;i++) cout<<num[i].fi<<" ";
        // cout<<endl;

        for(int i=1;i<=n;i++){
            if(tot+num[i].se > m){
                continue;
            }
            if(num[i].se==1) res+=num[i].fi/2;
            else res+=num[i].fi;
            tot+=num[i].se;
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=w[i];j--){
                f[j]=max(f[j],f[j-w[i]]+a[i]);
                maxx=max(f[j],maxx);
            }
        }
        if(res>=maxx) ans=(ans+1)%mod;
        // cout<<res<<" "<<maxx<<endl;
        return;
    }
    b[dep]=a[dep]*2; w[dep]=1;
    dfs(dep+1);
    b[dep]=a[dep]; w[dep]=2;
    dfs(dep+1);
}
void init()
{
    ans=0;
    
}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    while(T--){
        init();
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    
    return 0;
}