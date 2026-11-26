#include<bits/stdc++.h>
using namespace std;
long long a,b,s[100001],ans,q[100001],minn=3e18,w[100001];
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdin);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a,&b);
        s[i]=a;
        w[i]=b;
        q[i]=a+b;
    }
    sort(s+1,s+n+1);
    for(long long i=1;i<=n;i++)
    {
        minn=min(minn,q[i]);
    }
    ans+=(m/minn)*2;
    m%=minn;
    for(long long i=1;i<=n;i++)
    {
        if(m-s[i]<0)break;
        else
        {
            m-=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
