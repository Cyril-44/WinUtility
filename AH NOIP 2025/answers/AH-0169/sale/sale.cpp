#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,a;
const int mod=998244353;
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int ans=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
        }
        for(int i=1;i<=n;i++)
            ans=(ans*2)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}
