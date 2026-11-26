#include<bits/stdc++.h>

using namespace std;
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
void write(unsigned long long a)
{
    if(a!=0)
    {
    write(a/10);
    printf("%d",a%10);
    }
}
unsigned long long POW(unsigned long long a,int b)
{
unsigned long long sum=1;
    while(b!=0)
    {
        if(b&1==1) sum=sum*a;
    a=a*a;
    b>>=1;
    }
    return sum;
}
int n,a[50005],q,l[1055],r[1055];
long long sum;
const unsigned long long M=pow(2,64);
map<int,bool> m1;
map<int,unsigned long long> m2;

int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
    a[i]=read();
    sum+=a[i];
    }
    q=read();
    for(int i=1;i<=q;i++)
    {
    l[i]=read();
    r[i]=read();
    }
    long long sum1[50005],sum2[50005];
    sum1[0]=0;
        for(int i=1;i<=n;i++)
        {
        sum1[i]=sum1[i-1]+a[i];
        }
    sum2[n+1]=0;
        for(int i=n;i>=1;i--)
        {
        sum2[i]=sum2[i+1]+a[i];
        }
    if(q==1)
    {
    unsigned long long ans=0;
    long long cnt;
        for(int i=1;i<=n;i++,cnt=-1e12)
        {
            for(int j=l[1];j<=r[1];j++)
            {
                for(int k=max(1,i-j+1);k<=min(i,n-j+1);k++)
                {
                cnt=max(cnt,sum-sum1[k-1]-sum2[k+j]);
                }
            }
            if(cnt<0) ans=ans^(M+cnt*i+1);
            else ans=ans^(cnt*i);
        }
    write(ans);
        if(ans==0) printf("0");
    }
    else if(q==1024 && l[1]==r[1] && l[2]==r[2])
    {
        for(int i=1;i<=q;i++)
        {
        m1[l[i]]=1;
        }
    unsigned long long ans;
    long long cnt;
        for(int j=1;j<=n;j++,ans=0)
        {
            if(!m1[j]) continue;
            for(int i=1;i<=n;i++,cnt=-1e12)
            {
                for(int k=max(1,i-j+1);k<=min(i,n-j+1);k++)
                {
                cnt=max(cnt,sum-sum1[k-1]-sum2[k+j]);
                }
                if(cnt<0) ans=ans^(M+cnt*i+1);
                else ans=ans^(cnt*i);
            }
        m2[j]=ans;
        }
        for(int i=1;i<=q;i++)
        {
        write(m2[l[i]]);
            if(m2[l[i]]==0) printf("0");
        printf("\n");
        }
    }
    else
    {
    unsigned long long ans;
    long long cnt;
        for(int p=1;p<=q;p++,ans=0)
        {
            for(int i=1;i<=n;i++,cnt=-1e12)
            {
                for(int j=l[p];j<=r[p];j++)
                {
                    for(int k=max(1,i-j+1);k<=min(i,n-j+1);k++)
                    {
                    cnt=max(cnt,sum-sum1[k-1]-sum2[k+j]);
                    }
                }
                if(cnt<0) ans=ans^(M+cnt*i+1);
                else ans=ans^(cnt*i);
            }
        write(ans);
            if(ans==0) printf("0");
        printf("\n");
        }
    }
    return 0;
}
