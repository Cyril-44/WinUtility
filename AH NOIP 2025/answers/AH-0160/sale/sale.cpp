#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[5005],b[5005],f[105][205],cnt=0;
struct node
{
    double x;
    long long id,w,xian;
}c[105];
bool cmp(node a,node b)
{
    if(a.x!=b.x)
    {
        return a.x>b.x;
    }
    if(a.w!=b.w)
    {
        return a.w>b.w;
    }
    return a.id<b.id;
}
long long n,w;
bool check()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            f[i][j]=f[i-1][j]>=f[i][j-1]?f[i-1][j]:f[i][j-1];
            if(j>=b[i])
            {
                f[i][j]=f[i][j]>=f[i-1][j-b[i]]+a[i]?f[i][j]:f[i-1][j-b[i]]+a[i];
            }
            //cout<<b[i]<<" ";
            //cout<<f[i][j]<<" ";
        }
        //cout<<endl;
    }
    long long res=f[n][w];
    for(int i=1;i<=n;i++)
    {
        c[i].w=a[i];
        c[i].id=i;
        c[i].x=a[i]*1.0/b[i];
        c[i].xian=b[i];
    }
    long long p=w;
    long long ans=0;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(p>=c[i].xian)
        {
            p-=c[i].xian;
            ans+=c[i].w;
        }
        if(p==0)
        {
            break;
        }
    }
    //cout<<endl;
    //for(int i=1;i<=n;i++)
    //{
    //    cout<<b[i]<<" ";
    //}
    //cout<<endl;
    //cout<<ans<<" "<<res<<endl;
    //cout<<endl;
    return ans==res;
}
void dfs(int x)
{
    if(x==n+1)
    {
        cnt+=check();
        cnt%=998244353;
        return;
    }
    b[x]=2;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
    return;
}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c>=1&&c<=5)
    {
        while(t--)
        {
            cnt=0;
            cin>>n>>w;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            dfs(1);
            printf("%lld,\n",cnt);
        }
    }
    if(c==18)
    {
        while(t--)
        {
            long long ans=1;
            cin>>n>>w;
            for(int i=1;i<=n;i++)
            {
                ans*=2;
                ans%=998244353;
                cin>>a[i];
            }
            cout<<ans<<endl;
        }
    }
    if((c>=7&&c<=9)||(c==14||c==15))
    {
        while(t--)
        {
            long long ans=1;
            cin>>n>>w;
            long long maxn=-1;
            for(int i=1;i<=n;i++)
            {
                ans*=2;
                ans%=998244353;
                cin>>a[i];
                maxn=max(maxn,a[i]);
            }
            long long maxnq=maxn/2;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>maxnq&&a[i]!=maxn)
                {
                    ans--;
                    ans+=998244353;
                    ans%=998244353;
                }
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
