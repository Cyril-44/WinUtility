#include<bits/stdc++.h>

using namespace std;
const int M=998244353;
int read()
{
int f=1,sum=0;
char ch;
ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
    ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
    sum=(sum<<1)+(sum<<3)+(ch^48);
    ch=getchar();
    }
    return sum*f;
}
bool cmp(int x,int y)
{
    return x>y;
}
long long POW(long long a,int b)
{
long long sum=1;
    while(b!=0)
    {
        if(b&1==1) sum=sum*a%M;
    a=a*a%M;
    b>>=1;
    }
    return sum;
}
long long stair(int x,int y)
{
long long sum=1;
    for(int i=x;i<=y;i++)
    {
    sum=sum*i%M;
    }
    return sum;
}
int a[5005],ans;
struct node
{
int id,num;
}f[5005];
bool cmp2(node x,node y)
{
    if(x.num!=y.num) return x.num>y.num;
    if(a[x.id]!=a[y.id]) return a[x.id]>a[y.id];
    return x.id<y.id;
}
int n,m;
int dfs(int x,int minn)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
        f[i].num=a[i]/f[i].num;
        }
    sort(f+1,f+n+1,cmp2);
    int lst=m,cnt=0;
        for(int i=1;i<=n;i++)
        {
        lst-=a[f[i].id]/f[i].num;
            if(lst==0) cnt++;
            if(lst==-1)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[f[j].id]/f[j].num==1)
                    {
                        if(a[f[j].id]+a[f[i-1].id]>a[f[i].id]) cnt++;
                        else break;
                    }
                }
            }
        }
        return cnt;
    }
    f[x].id=x;
    f[x].num=1;
    int summ=0;
    summ+=dfs(x+1,a[x]);
    f[x].num=2;
    summ+=dfs(x+1,minn);
    return summ;
}

int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c,t;
    bool f1,f2;
    c=read();
    t=read();
    while(t--)
    {
    n=read();
    m=read();
    f1=1;
    f2=1;
    ans=0;
        for(int i=1;i<=n;i++)
        {
        a[i]=read();
            if(i>=2 && a[i]!=a[i-1]) f1=0;
            if(a[i]<=5e8) f2=0;
        }
        if(m==2*n-1)
        {
        printf("%d\n",POW(2,n));
        continue;
        }
        if(f1)
        {
        printf("%d\n",POW(2,n));
        continue;
        }
        if(m==2)
        {
        sort(a+1,a+n+1,cmp);
        ans=POW(2,n);
            for(int i=1;i<=n;i++)
            {
            }
        printf("%d\n",ans);
        continue;
        }
        if(f2)
        {
        ans=POW(2,n);
        sort(a+1,a+n+1,cmp);
            for(int i=1;i<=m-1;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                ans=(ans-stair(n-i-1,m-i)+M)%M;
                }
            }
        printf("%d\n",ans);
        continue;
        }
    sort(a+1,a+n+1,cmp);
    cout<<dfs(1,1e9)<<endl;
    }
    return 0;
}
