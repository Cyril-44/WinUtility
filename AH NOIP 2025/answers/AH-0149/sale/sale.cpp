#include <bits/stdc++.h>
#define maxn 5050
#define mod 998244353
using namespace std;
long long n,m;
double a[maxn];
int c,t;
long long ans;
bool cmp(double x,double y)
{
    return x>y;
}
long long two(int n)
{
    long long s=1;
    for(int i=1;i<=n;i++)
        s=s*2%mod;
    return s;
}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(m==(2*n-1))
        {
            ans=1;
            for(int i=1;i<=n;i++)
            {
                ans*=2;
                ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}

