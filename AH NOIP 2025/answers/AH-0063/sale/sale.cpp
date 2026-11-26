#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll w[50005];
ll n,m;
struct node{
    ll x;
    int id;
}a[50005],b[50005];
bool cmp(node x,node y)
{
    if(x.x!=y.x)
        return x.x>y.x;
    else if(x.x*w[x.id]!=y.x*w[y.id])
        return x.x*w[x.id]>y.x*w[y.id];
    else return x.id<y.id;
}
ll f[50005];
bool check()
{
    ll m1=m;
    for(int i=1;i<=n;i++)
    {
        b[i].id=i;
        b[i].x=a[i].x;
        if(w[i]==1)
            b[i].x*=2;
    }
    sort(b+1,b+1+n,cmp);
    ll cnt=0;
    for(int i=1;i<=n;i++)
        if(m1>=w[b[i].id])
        {
            m1-=w[b[i].id];
            cnt+=a[b[i].id].x;
        }
    //计算正常取的最大值
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            f[j]=max(f[j],f[j-w[i]]+a[i].x);
    //for(int i=1;i<=n;i++)
    //    cout<<w[i]<<" ";
    //cout<<"cnt"<<cnt<<" f[m]:"<<f[m]<<"\n";
    return cnt==f[m];
}
ll ans=0;
void dfs(int pos)
{
    if(pos>n)
    {
        if(check())
            ans=(ans+1)%mod;
        return;
    }
    w[pos]=1;
    dfs(pos+1);
    w[pos]=2;
    dfs(pos+1);
}
int C,T;
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>C>>T;
    if(C>=0&&C<=5)
    {
        while(T--)
        {
            ans=0;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&a[i].x);
                a[i].id=i;
            }
            dfs(1);
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(C==18)
    {
        while(T--)
        {
            ans=1;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&a[i].x);
                a[i].id=i;
            }
            for(int i=1;i<=n;i++)
                ans=ans*2%mod;
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(C==16)
    {
        while(T--)
        {
            ans=1;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&a[i].x);
                a[i].id=i;
            }
            for(int i=1;i<=n;i++)
                w[i]=2;
            for(int i=1;i<=n;i++)
                ans=ans*2%mod;
            if(!check())
                ans=(ans-1+mod)%mod;
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(C==17)
    {
        while(T--)
        {
            ans=1;
            scanf("%lld%lld",&n,&m);
            for(int i=1;i<=n;i++)
            {
                scanf("%lld",&a[i].x);
                a[i].id=i;
            }
            for(int i=1;i<=n;i++)
                ans=ans*2%mod;
            for(int i=1;i<=n;i++)
                w[i]=2;
            if(!check())
                ans=(ans-1+mod)%mod;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    if(i!=j)
                        w[j]=2;
                    else
                        w[j]=1;
                if(!check())
                    ans=(ans-1+mod)%mod;
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
}
