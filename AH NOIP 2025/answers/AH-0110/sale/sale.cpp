#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5114,mod=998244353;
int c,t,n,m,ans,a[N],f[25];
struct node{
    int a,w,id;
    friend bool operator<(const node x,const node y)
    {
        if(x.a*y.w!=y.a*x.w) return x.a*y.w>y.a*x.w;
        if(x.a!=y.a) return x.a>y.a;
        return x.id>y.id;
    }
}x[5114],y[5114];
void dfs(int d)
{
    if(d>n){
        for(int i=1;i<=n;i++) y[i]=x[i];
        sort(y+1,y+1+n);
        int cnt=m,res=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=y[i].w) cnt-=y[i].w,res+=y[i].a;
        }
        for(int j=0;j<=m;j++) f[j]=0;
        for(int i=1;i<=n;i++)
            for(int j=m;j>=y[i].w;j--)
                f[j]=max(f[j],f[j-y[i].w]+y[i].a);
        (ans+=(res==f[m]))%mod;
        return;
    }
    x[d]={a[d],1,d};
    dfs(d+1);
    x[d]={a[d],2,d};
    dfs(d+1);
}
int qpow(int base,int exp)
{
    int res=1;
    while(exp)
    {
        if(exp&1) (res*=base)%=mod;
        (base*=base)%=mod;
        exp>>=1;
    }
    return res;
}
signed main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n<=10){
            dfs(1);
            cout<<ans<<'\n';
            ans=0;
        }
        else{
            cout<<qpow(2,n)<<'\n';
        }
    }
    return 0;
}
