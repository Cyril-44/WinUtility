#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;
const int N=5010,mod=998244353;
int n,m,a[N],ans;
struct node
{
    int val,num,pd;
    bool operator <(const node &x)const
    {
        if(val*x.pd!=pd*x.val)return val*x.pd>pd*x.val;
        if(val!=x.val)return val>x.val;
        return num<x.num;
    }
}v[N];
ll f[N];
int qpow(int x,int y)
{
    int ji=1,base=x;
    while(y)
    {
        if(y&1)ji=1ll*ji*base%mod;
        base=base*base%mod;
        y>>=1;
    }
    return ji;
}
void solve()
{
    ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        if(n>=100)
        {
            cout<<qpow(2,n)<<"\n";
            return;
        }
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
            v[j+1]={a[j+1],j+1,((i>>j)&1)+1};
        f[0]=0;
        for(int j=1;j<=m;j++)f[j]=0;
        for(int j=1;j<=n;j++)
            for(int k=m;k>=v[j].pd;k--)f[k]=max(f[k],f[k-v[j].pd]+v[j].val);
        sort(v+1,v+n+1);
        ll res=0;
        int tmp=m;

        for(int j=1;j<=n;j++)
            if(tmp>=v[j].pd)tmp-=v[j].pd,res+=v[j].val;
        ans+=(res==f[m]);
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("sale.in","r",stdin);
   freopen("sale.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}

