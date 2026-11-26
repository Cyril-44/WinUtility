#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[10005],ans;
bool f[10005];
struct node
{
    double x;
    int op;
}b[10005];
inline bool cmp2(node p,node q)
{
    if(p.x==q.x) return p.op>q.op;
    return p.x>q.x;
}
inline bool check()
{
    for(int i=1;i<=n;++i)
    {
        if(!f[i]) b[i].x=a[i],b[i].op=1;
        else b[i].x=1.0*a[i]/2,b[i].op=2;
    }
    sort(b+1,b+1+n,cmp2);
    int now=m,pre=0;
    for(int i=1,pre=0;i<=n;++i)
    {
        if(now>b[i].op) now-=b[i].op;
        else
        {
            if(now==b[i].op) return 1;
            if(pre==0) return 1;
            int j;
            for(j=i+1;j<=n;++j)
            {
                if(b[j].op==1) return (b[j].x+b[pre].x)>=b[i].x*2;
            }
            return b[pre].x>=b[i].x*2;
        }
        if(b[i].op==1) pre=i;
    }
    return 1;
}
inline void dfs(int x)
{
    if(x>n)
    {
        if(check()) ++ans;
        return;
    }
    f[x]=0;
    dfs(x+1);
    f[x]=1;
    dfs(x+1);
    return;
}
inline ll ksm(ll x,int y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
inline bool cmp(int x,int y){return x>y;}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int id,T;
    scanf("%d %d",&id,&T);
    if(id==16||id==18)
    {
        while(T--)
        {
            scanf("%d %d",&n,&m);
            for(int i=1;i<=n;++i)
            {
                scanf("%d",&a[i]);
            }
            printf("%lld\n",ksm(2ll,n));
        }
        return 0;
    }
    if(id==17)
    {
        while(T--)
        {
            scanf("%d %d",&n,&m);
            for(int i=1;i<=n;++i)
            {
                scanf("%d",&a[i]);
            }
            sort(a+1,a+1+n,cmp);
            ll sum=ksm(2ll,n)-(a[n]>a[n-1]/2);
            printf("%lld\n",(sum+mod)%mod);
        }
        return 0;
    }
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
