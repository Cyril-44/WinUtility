#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long n;
double m,x[N],y[N],minn=99999999999999999,ans;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        minn=min(minn,x[i]+y[i]);
    }
    n++;
    minn/=2;
    x[n]=minn;
    sort(x+1,x+n+1);
    for(long long i=1;i<=n;i++)
    {
        if(x[i]==minn)break;
        if(x[i]<=m)
        {
            m-=x[i];
            ans++;
            //cout<<x[i]<<' '<<ans<<'\n';
        }
    }
    long long u=m/minn;
    cout<<ans+u;
    return 0;
}
