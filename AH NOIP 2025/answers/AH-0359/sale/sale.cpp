#include<bits/stdc++.h>
#define int long long
const long long mod=998244353;
const int N=5e3+6;
using namespace std;
int n,m;
int a[N];
int b[N];
int jc[N][N];
int mi2[N];
bool cmp(int a,int b)
{
    a>b;
}
int C(int nn,int i)
{
    return (jc[i][nn]+mod-jc[i][nn-1])%mod;
}
signed main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    for(int i=0;i<=N-2;i++)
        jc[0][i]=i+1;
    for(int i=1;i<=N-2;i++)
        for(int j=i;j<=N-1;j++)
    {
        jc[i][j]=(jc[i-1][j-1]+jc[i][j-1])%mod;
    }
    mi2[0]=1;
    for(int i=1;i<=N-2;i++)
        mi2[i]=(mi2[i-1]*2)%mod;
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        int rans=mi2[n];
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1,cmp);
        int hz=1;
        for(int i=1;i<=n;i++)
        {
            for(;hz<=n;hz++)
            {
                if(a[hz]*2<=a[i])
                    break;
            }
            int lng12=hz-1-1;
            int lng1=i-1;
            int lng2=lng12-lng1;
            if(m-(lng12+lng1)<=1&&m-(lng1)>=1)
            {
                int hf=hz;
                for(int b2=0;b2<=lng1;b2++)
                {
                    int x1=lng1+b2;
                    int x2=(m-1)-x1;
                    if(b2==lng1&&x2==0)
                        continue;
                    if(x2>=0&&x2<=lng2)
                    {
                        int ql=lng1+x2;
                        if(ql>=i)
                            ql++;
                        for(;hf<=n;hf++)
                        {
                            if(a[ql]+a[hf]<a[i])
                                break;
                        }
                        if(hf==n+1)
                            break;
                            int cc=(C(lng1,b2)*((mi2[n-hf+1]+mod)%mod))%mod;
                            ans=(ans+cc)%mod;
                    }
                }
            }
        }
        cout<<(rans+mod-ans)%mod<<'\n';
    }
    return 0;
}
