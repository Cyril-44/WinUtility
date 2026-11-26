#include<bits/stdc++.h>
using namespace std;
long long C,T,n,m,a[55],p[55],r,u,v,dp[55][505],ans;
struct candy{
    long long w,id;
    long double v;
}c[5005];
bool cmp(candy x,candy y)
{
    if(x.v>y.v)return 1;
    else if(x.v<y.v)return 0;
    else{
        if(a[x.id]>a[y.id])return 1;
        else if(a[x.id]<a[y.id])return 0;
        else return x.id<y.id;
    }
}
void nxt()
{
	p[0]++;
	long long e=0;
	while(p[e]>1)
    {
        p[e]=0;
        e++;
        p[e]++;
    }
}
void work()
{
    for(long long i=0;i<n;i++)
    {
        c[i].id=i;
        c[i].w=p[i]%2+1;
        c[i].v=a[i]*1.0/c[i].w*1.0;
    }
    sort(c,c+n,cmp);
    long long k=m,tot=0,res=0;
    for(long long i=0;i<n;i++)
    {
        if(k>=c[i].w)
        {
            k-=c[i].w;
            tot+=a[c[i].id];
        }
        else continue;
    }
    u=tot;
    for(long long i=0;i<n;i++)for(long long j=0;j<=m;j++)dp[i][j]=0;
    dp[0][0]=0;
    dp[0][c[0].w]=a[c[0].id];
    for(long long i=1;i<n;i++)
    {
        for(long long j=0;j<c[i].w;j++)dp[i][j]=dp[i-1][j];
        for(long long j=c[i].w;j<=m;j++)dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i].w]+a[c[i].id]) ;
    }
    for(long long i=0;i<=m;i++)res=max(res,dp[n-1][i]);
    v=res;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
    cin>>C>>T;
    if(C<6)
    {
        while(T--)
        {
			ans=0;
            cin>>n>>m;
            r=1;
            for(long long i=0;i<n;i++)
            {
                cin>>a[i];
                p[i]=0;
                r*=2;
            }
            for(long long i=0;i<r;i++)
            {
                work();
                if(u>=v)ans++;
                ans=ans%998244353;
                nxt();
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
