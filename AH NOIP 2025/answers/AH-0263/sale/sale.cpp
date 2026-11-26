#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[5001];
int ans=1;
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>n>>m;
    for(int u=1;u<=t;u++)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            ans*=2;
            ans%=998244353;
        }
        cout<<ans<<endl;
    }
    return 0;
}
