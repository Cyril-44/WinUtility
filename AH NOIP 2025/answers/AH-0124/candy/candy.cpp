#include<bits/stdc++.h>

using namespace std;
long long read()
{
long long f=1,sum=0;
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
int n;
long long m,sum,ans,cnt;
int x[100005],y[100005],minn=2e9+1;

int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
    x[i]=read();
    y[i]=read();
    minn=min(minn,x[i]+y[i]);
    }
    sort(x+1,x+n+1);
    for(int i=0;i<=n;i++)
    {
    sum+=x[i];
    cnt=(m-sum)/minn*2+i;
    ans=max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}
