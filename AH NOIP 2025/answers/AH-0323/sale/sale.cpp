#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
const long long M=998244353;
long long C[5005][5005];
long long pw2[5005];
struct node{
    int x,y;
};
node b[5005];
bool cmp(node x,node y)
{
    if(x.x*y.y!=x.y*y.x)
        return x.x*y.y>x.y*y.x;
    return x.x>y.x;
}
bool bot[5005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    C[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        C[i][0]=C[i][i]=0;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    }
    pw2[0]=1;
    for(int i=1;i<=5000;i++)
        pw2[i]=pw2[i-1]*2%M;
    int tst,T;
    cin>>tst>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(m==1)
        {
            cout<<pw2[n]<<"\n";
            continue;
        }
        if(tst==18 || tst==16)
        {
            cout<<pw2[n]<<"\n";
            continue;
        }
        if(tst<=5)
        {
            int cnt=0;
            for(int dd=0;dd<(1<<n);dd++)
            {
                for(int i=1;i<=n;i++)
                {
                    if(dd&(1<<(i-1)))
                        b[i].y=1;
                    else
                        b[i].y=2;
                    b[i].x=a[i];
                }
                sort(b+1,b+n+1,cmp);
                int mo=m,sum=0;
                int l1=1e9,l2=1e9;
                for(int i=1;i<=n;i++)
                {
                    if(mo>=b[i].y)
                    {
                        mo-=b[i].y,sum+=b[i].x;
                        if(b[i].y==1)
                        {
                            if(b[i].x<l1)
                                l2=l1,l1=b[i].x;
                            else if(b[i].x<l2)
                                l2=b[i].x;
                        }
                        bot[i]=1;
                    }
                    else
                        bot[i]=0;
                }
                bool flag=1;
                if(mo==1)
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(!bot[i] && b[i].x>l1)
                            flag=0;
                    }
                }
                if(mo==0)
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(!bot[i] && b[i].x>l1+l2)
                            flag=0;
                    }
                }
                cnt+=flag;
            }
            cout<<cnt<<"\n";
            continue;
        }
        if(tst==7 || tst==8 || tst==9 || tst==14 || tst==15)
        {
            sort(a+1,a+n+1,greater<int>());
            long long ans=0;
            //first 2 at 1
            for(int i=2;i<=n;i++)
            {
                if(a[i]*2<=a[1])
                    break;
                ans++;
                for(int j=i+1;j<=n;j++)
                {
                    if(a[i]+a[j]<a[1])
                    {
                        ans=(ans+pw2[n-j])%M;
                    }
                }
            }
            ans=(pw2[n]-ans+2*M)%M;
            cout<<ans<<"\n";
            continue;
        }
        if(tst==17)
        {
            sort(a+1,a+n+1);
            long long ans=0;
            if(a[1]*2>a[2] && a[1]<a[2])
                ans++;
            ans=(pw2[n]-ans+2*M)%M;
            cout<<ans<<"\n";
            continue;
        }
    }
    return 0;
}
