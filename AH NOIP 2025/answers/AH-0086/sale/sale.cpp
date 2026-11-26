#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
int c,t;
const ll mod=998244353;
ll a[5011];
struct node{
    int x,y,num;
};
node p[11];
bool cmp2(node c,node d)
{
    double pp=1.0*c.x/c.y,qq=1.0*d.x/d.y;
    if(pp==qq)
    {
        if(c.x==d.x) return c.num<d.num;
        return c.x>d.x;
    }
    return pp>qq;
}
bool cmp(int x,int y)
{
    return x>y;
}
inline ll ksm(ll x,ll y)
{
    ll res=x,mul=1;
    while(y)
    {
        if(y&1)mul=mul*res%mod;
        res=res*res%mod;
        y>>=1;
    }
    return mul;
}
int main()
{
 freopen("sale.in","r",stdin);
freopen("sale.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(c<=5)
        {
            ll maxn=0,cnt=0;
            for(int i=0;i<(1<<n);i++)
            {
                for(int i=1;i<=n;i++) p[i].x=a[i],p[i].num=i;
                for(int j=1;j<=n;j++)
                {
                    p[j].y=2;
                    if((1<<j-1)&i) p[j].y=1;
                }
                sort(p+1,p+n+1,cmp2);
                ll sum=0,mm=m;
                for(int i=1;i<=n;i++)
                {
                    if(p[i].y>mm) continue;
                    sum+=p[i].x,mm-=p[i].y;
                    printf("%d ",p[i].num);
                }
                //printf("%d %d\n",sum,mm);
                if(sum>maxn) maxn=sum,cnt=1;
                else if(sum==maxn) cnt++;
            }
            printf("%d\n",n-cnt);
            continue;
        }
        sort(a+1,a+n+1,cmp);
        printf("%lld\n",ksm(2,n));
    }
    return 0;
}
